#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXM = 100;
int vec[MAXM];
int matrix[MAXM][MAXM];
int m;
long long n;

void matMult(int mat1[MAXM][MAXM], int mat2[MAXM][MAXM], int save[MAXM][MAXM])
{
    int temp[MAXM][MAXM];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int res = 0;
            for (int k = 0; k < m; k++)
            {
                res = (int) (res + (long long) mat1[i][k] * mat2[k][j] % MOD) % MOD;
            }
            temp[i][j] = res;
        }
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            save[i][j] = temp[i][j];
}

void modpow(int mat[MAXM][MAXM], long long exp)
{
    int temp[MAXM][MAXM];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            temp[i][j] = mat[i][j];
    exp--;
    for (int i = 0; i < 62; i++)
    {
        if (exp & ((long long) 1 << i))
        {
            matMult(temp, mat, mat);
        }
        matMult(temp, temp, temp);
    }
}

int main()
{
    cin >> n >> m;
    if (n < m)
    {
        cout << 1 << endl;
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            vec[i] = 1;
        }
        matrix[0][0] = matrix[0][m - 1] = 1;
        for (int i = 1; i < m; i++)
        {
            matrix[i][i - 1] = 1;
        }
        modpow(matrix, n - (m - 1));
        /*
        cout << "matrix" << endl;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << matrix[i][j] << " " ;
            }
            cout << endl;
        }
        cout << "vector" << endl;
        for (int i = 0;i  < m; i++)
            cout << vec[i] << " ";
        cout << endl;
        */
        int ans[MAXM];
        for (int i = 0; i < m; i++)
        {
            int res = 0;
            for (int j = 0; j < m; j++)
            {
                res = (int) (res + (long long) matrix[i][j] * vec[j] % MOD) % MOD;
            }
            ans[i] = res;
        }
        /*
        cout << "tes" << endl;
        for (int i = 0; i < m; i++)
            cout << ans[i] << " ";
        */
        cout << ans[0] << endl;
    }
    return 0;
}