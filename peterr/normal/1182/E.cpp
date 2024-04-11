#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MOD2 = MOD - 1;

void vecMult(int mat[5][5], int vec[5])
{
    long double temp[5];
    for (int i = 0; i < 5; i++)
    {
        int sum = 0;
        for (int k = 0; k < 5; k++)
            sum = (sum + ((long long) mat[i][k] * vec[k]) % MOD2) % MOD2;
        temp[i] = sum;
    }
    for (int i = 0; i < 5; i++)
        vec[i] = temp[i];
}

void matrixMult(int opand1[5][5], int opand2[5][5], int save[5][5])
{
    int temp[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int sum = 0;
            for (int k = 0; k < 5; k++)
                sum = (sum + ((long long) opand1[i][k] * opand2[k][j] % MOD2)) % MOD2;
            temp[i][j] = sum;
        }
    }
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            save[i][j] = temp[i][j];
}

void matrixPow(int mat[5][5], long long e)
{
    if (e <= 1)
        return;
    int temp[5][5];
    matrixMult(mat, mat, temp);
    matrixPow(temp, e / 2);
    if (e % 2 == 1)
        matrixMult(temp, mat, temp);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            mat[i][j] = temp[i][j];
}

int exp(int b, int e)
{
    if (e == 0)
        return 1;
    if (e == 1)
        return b % MOD;
    int temp = (long long) b * b % MOD;
    if (e % 2 == 0)
        return exp(temp, e / 2);
    else
        return (long long) b * exp(temp, e / 2) % MOD;
}

int main()
{
    long long n;
    int f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;
    int fMat[5][5] = {{1, 1, 1, 0, 0}, {1, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    int fVal[5][5] = {{2, 3, 4, 0, 0}, {1, 2, 2, 0, 0}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    int cMat[5][5] = {{1, 1, 1, 1, 0}, {1, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 0, 0, 1, 2}, {0, 0, 0, 0, 1}};
    int cVec[5] = {14, 6, 2, 8, 1};
    if (n > 6)
    {
        matrixPow(fMat, n - 6);
        matrixMult(fMat, fVal, fVal);
        matrixPow(cMat, n - 6);
        vecMult(cMat, cVec);
    }
    else
    {
        fVal[0][0] = fVal[6 - n][0];
        fVal[0][1] = fVal[6 - n][1];
        fVal[0][2] = fVal[6 - n][2];
        cVec[0] = cVec[6 - n];
    }
    int ans = 1;
    ans = ((long long) ans * exp(f1, fVal[0][0])) % MOD;
    ans = ((long long) ans * exp(f2, fVal[0][1])) % MOD;
    ans = ((long long) ans * exp(f3, fVal[0][2])) % MOD;
    ans = ((long long) ans * exp(c, cVec[0])) % MOD;

    cout << ans;

    return 0;
}