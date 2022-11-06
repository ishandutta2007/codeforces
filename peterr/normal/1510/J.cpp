#include <bits/stdc++.h>

using namespace std;

vector<int> a;

void printAns(vector<int> vec)
{
    cout << vec.size() << "\n";
    for (int x : vec)
        cout << x << " ";
    cout << "\n";
}

bool checkOne(string s, vector<int> &ans)
{
    ans.clear();
    int n = (int) s.length();
    int l = s.find("#");
    int r = s.rfind("#");
    if (!(l & 1) || ((n - r) & 1))
        return false;
    for (int i = 0; i < l / 2; i++)
        ans.push_back(1);
    for (int i = 1; i < (int) a.size() - 1; i++)
    {
        if (!(i & 1) && (a[i] & 1))
            return false;
        if (i & 1)
            ans.push_back(a[i] + 1);
        else
        {
            for (int j = 0; j < (a[i] - 1) / 2; j++)
            {
                ans.push_back(1);
            }
        }
    }
    for (int i = 0; i < (n - r - 1) / 2; i++)
        ans.push_back(1);
    return true;
}

void fillGap(int len, vector<int> &ans)
{
    if (len <= 0)
        return;
    if (!(len & 1))
    {
        ans.push_back(2);
        len -= 3;
    }
    for (int i = 0; i < (len + 1) / 2; i++)
        ans.push_back(1);
}

bool checkTwo(string s, vector<int> &ans)
{
    ans.clear();
    if (a[0] == 1 || a[0] == 3)
        return false;
    if (a.back() == 1 || a.back() == 3)
        return false;
    for (int i = 2; i < (int) a.size() - 1; i += 2)
    {
        if (a[i] == 1 || a[i] == 2 || a[i] == 4)
            return false;
    }
    fillGap(a[0] - 3, ans);
    for (int i = 1; i < (int) a.size() - 1; i++)
    {
        if (i & 1)
        {
            ans.push_back(a[i] + 2);
        }
        else
        {
            fillGap(a[i] - 4, ans);
        }
    }
    fillGap(a.back() - 3, ans);
    return true;
}

bool checkThree(string s, vector<int> &ans)
{
    ans.clear();
    if (a[0] == 1 || a[0] == 2 || a[0] == 4)
        return false;
    if (a.back() == 1 || a.back() == 2 || a.back() == 4)
        return false;
    for (int i = 2; i < (int) a.size() - 1; i += 2)
    {
        if (a[i] == 1 || a[i] == 2 || a[i] == 3 || a[i] == 5)
            return false;
    }
    fillGap(a[0] - 4, ans);
    for (int i = 1; i < (int) a.size() - 1; i++)
    {
        if (i & 1)
        {
            ans.push_back(a[i] + 3);
        }
        else
        {
            fillGap(a[i] - 5, ans);
        }
    }
    fillGap(a.back() - 4, ans);
    return true;
}

int main()
{
    string s;
    cin >> s;
    int n = (int) s.length();
    if (s.find("#") == string::npos)
    {
        cout << "0\n\n";
        return 0;
    }
    if (s[0] == '#' && s[n - 1] == '#')
    {
        bool good = true;
        int cnt = 0;
        vector<int> vec;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '#')
                cnt++;
            else
            {
                vec.push_back(cnt);
                cnt = 0;
            }
            if (i + 1 < n && s[i] == '_' && s[i + 1] == '_')
                good = false;
        }
        vec.push_back(cnt);
        if (good)
        {
            printAns(vec);
            return 0;
        }
    }
    if (s[0] == '#' || s[n - 1] == '#')
    {
        cout << "-1\n";
        return 0;
    }
    int ptr = 0;
    while (ptr < n)
    {
        char ch = s[ptr];
        int cnt = 0;
        while (ptr < n && s[ptr] == ch)
        {
            ptr++;
            cnt++;
        }
        a.push_back(cnt);
    }
    /*
    for (int x : a)
        cout << "x " << x << endl;
    */
    vector<int> ans;
    if (checkOne(s, ans))
    {
        printAns(ans);
        return 0;
    }
    if (checkTwo(s, ans))
    {
        printAns(ans);
        return 0;
    }
    if (checkThree(s, ans))
    {
        printAns(ans);
        return 0;
    }
    cout << "-1\n";
    return 0;
}