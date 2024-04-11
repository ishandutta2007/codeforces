#include <bits/stdc++.h>

using namespace std;
const int mod=1e9+11;
int hash1(string s)
{
    int hash=0;
    for(int i=0;i<s.size();i++)
    {
        hash=((long long)hash*28)%mod;
        hash+=s[i]-'a'+1;
    }
    return hash;
}
int main()
{
    int n;
    scanf("%i",&n);
    map<int,int> broj;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        int h=hash1(s);
        if(broj[h]==0)
        {
            printf("OK\n");
        }
        else
        {
            cout << s << broj[h] <<endl;
        }
        broj[h]++;
    }
    return 0;
}