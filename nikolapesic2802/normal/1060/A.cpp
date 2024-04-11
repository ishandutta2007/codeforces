#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
int main()
{
    int n;
    scanf("%i",&n);
    string s;
    cin >> s;
    int broj_8=0,broj_ostalih=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='8')
            broj_8++;
        else
            broj_ostalih++;
    }
    int maxx=n/11;
    if(broj_8>maxx)
    {
        int r=broj_8-maxx;
        broj_8=maxx;
        broj_ostalih+=r;
    }
    printf("%i\n",min(broj_8,broj_ostalih/10));
    return 0;
}