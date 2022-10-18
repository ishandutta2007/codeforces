#include <iostream>

using namespace std;

int main()
{
    long long n, let[300], used[2000],k = 1, t = 0, length=0;

    string s[1000];

    char a[300];

    cin >> n;

    getline(cin, s[0]);

    for (int i = 0; i < 100; i++)
    {
        let[i] = 0;
        a[i]='a';
        }

    for (int i = 0; i < 1000; i++)
    {
        used[i] = 0;
    }


    for (int i = 0; i < n; i++)
    {
        getline (cin, s[i]);
    }

    long long ans=0;

    while (ans<n)
    {
    for (int i = 0; i < 26; i++) let[i] = 0;


    for (int i = 0; i < n; i++)
    {

       if (used[i] == 0)
       {
        if (let[s[i][0]-'a'] == 0) let[s[i][0]-'a'] = -5000;

        for (int j = 1; j < s[i].size(); j++)
        {
            let[s[i][j] - 'a'] ++;
        }
       }
    }

    long long startlet = 0;

    for (int i = 0; i < 26; i ++) if (let[i] == -5000) startlet = i;

    long long start = 0;

    for (int i = 0; i < n; i ++)
        if (used[i] == 0 && s[i][0]-'a' == startlet)
    {
         start = i;
    }


    used[start] = 1;

    ans++;

    for (int i = 0 ; i < s[start].size(); i ++)
    {
        length++;
        a[length-1] = s[start][i];
    }

    t = 0;

    k=0;

    while (k < n)
    {
        long long place = -1;
        if (used[t] == 0)
        {

            for (int i = 0; i < length; i ++)
            {
                    if (s[t][0] == a[i]) place = i;
            }

            if (place > -1)
            {
                used[t] = 1;

                ans++;


                 if (place + s[t].size() > length)
                 {
                    int lengthhh=length;
                    for (int i = lengthhh; i < place+s[t].size(); i ++)
                    {
                        length ++;
                        a[length-1] = s[t][i-place];
                    }
                 }
            }
        }
        if (t == 0 && place == -1) k = 1;
        else if (t == 0) k = 0;
        else if (place == -1) k ++;

        t = ( t + 1 ) % n;
    }

    for (int i = 0; i < n ; i ++)
    {
        if (used[i] == 0)
        {
            int kokoko = 0;
            for (int j = 0; j < length; j ++) if (s[i][0] == a[j]) kokoko = 1;
            if (kokoko == 1)
            {
                used[i] = 1;
                ans++;
            }
        }
    }


    }


    for (int i = 0; i < length; i ++) cout << a[i];


    return 0;
}