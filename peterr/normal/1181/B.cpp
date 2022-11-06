#include <bits/stdc++.h>

using namespace std;

const int MAXL = 1E5;
int num[MAXL];
int* low;
int* temp;

void add(int mid, int L, int* save)
{
    bool carry = 0;
    int i = 0;
    while (L - 1 - i >= mid && mid - 1 - i >= 0)
    {
        int sum = num[L - 1 - i] + num[mid - 1 - i];
        if (carry)
        {
            sum++;
            carry = 0;
        }
        if (sum >= 10)
        {
            carry = 1;
            sum = sum % 10;
        }
        save[L - 1 - i] = sum;
        i++;
    }
    while (L - 1 - i >= mid)
    {
        save[L - 1 - i] = num[L - 1 - i];
        if (carry && num[L - 1 - i] == 9)
        {
            save[L - 1 - i] = 0;
        }
        else if (carry)
        {
            carry = 0;
            save[L - 1 - i]++;
        }
        i++;
    }
    while (mid - 1 - i >= 0)
    {
        save[L - 1 - i] = num[mid - 1 - i];
        if (carry && num[mid - 1 - i] == 9)
        {
            save[L - 1 - i] = 0;
        }
        else if (carry)
        {
            carry = 0;
            save[L - 1 - i]++;
        }
        i++;
    }

}

bool bigger(int a1[], int a2[], int L)
{
    for (int i = 0; i < L; i++)
    {
        if (a1[i] > a2[i])
            return true;
        if (a1[i] < a2[i])
            return false;

    }
    return false;
}

void check(int mid, int L)
{
    if (mid > 0 && mid < L && num[mid] != 0)
    {
        add(mid, L, temp);
        if (bigger(low, temp, L))
            low = temp;
        temp = new int[L];
        fill(temp, temp + L, 0);
    }
}

int main()
{
    int L;
    cin >> L;
    string s;
    cin >> s;
    for (int i = 0; i < L; i++)
    {
        num[i] = s[i] - '0';
    }
    int mid = L / 2 - 1;
    int i = 0;
    while (num[mid + i] == 0 && num[mid - i] == 0)
        i++;
    low = new int[L];
    temp = new int[L];
    fill(low, low + L, 9);
    fill(temp, temp + L, 0);
    check(mid + i, L);
    check(mid + i + 1, L);
    check(mid + i + 2, L);
    check(mid - i, L);
    check(mid - i - 1, L);
    check(mid - i - 2, L);
    int index = 0;
    while (low[index] == 0)
        index++;
    while (index < L)
        cout << low[index++];

    return 0;
}