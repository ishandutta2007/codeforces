#include<bits/stdc++.h>
using namespace std;
int kmp(string s)
{
    int n = s.length();
 
    int lps[n];
    lps[0] = 0;
 
    int len = 0;
    int i = 1;
    while(i < n)
    {
        if(s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len != 0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    int res = lps[n-1];
    return res;
}
 
int main()
{
    int n,i,j,k,x,y,ans,curr,temp,pjg,tc,m,r,c,rose=0,low,high;
    int zero = 0;
    int one = 0;
    string a,b;
    cin >> a >> b;
    int lena = a.length();
    int lenb = b.length();
    string jwb = "";
    for(i=0;i<lena;i++)
    {
        zero += (a[i] == '0');
        one += (a[i] == '1');
    }
    int need0 = 0;
    int need1 = 0;
    int len = kmp(b);
    for(i=0;i<lenb;i++)
    {
        need0 += (b[i] == '0');
        need1 += (b[i] == '1');
    }
    if(zero >= need0 && one >= need1)
    {
        jwb += b;
        zero -= need0;
        one -= need1;
    }
    else
    {
        cout << a << endl;
        return 0;
    }
    for(i=0;i<len;i++)
    {
        need0 -= (b[i] == '0');
        need1 -= (b[i] == '1');
    }
    b = b.substr(len, lenb-len);
    while(1)
    {
        if(zero >= need0 && one >= need1)
        {
            jwb += b;
            zero -= need0;
            one -= need1;
        }
        else
            break;
    }
    for(i=1;i<=zero;i++)
        jwb += '0';
    for(i=1;i<=one;i++)
        jwb += '1';
    cout << jwb << endl;
}