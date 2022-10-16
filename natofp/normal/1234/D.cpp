#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin>>s;
    set<int> a[26];
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        a[s[i]-'a'].insert(i);
    }
    int q; cin>>q;
    while(q--)
    {
        int id;
        cin>>id;
        if(id==1)
        {
            int pos; cin>>pos;
            pos--;
            char akt=s[pos];
            akt-='a';
            a[akt].erase(pos);
            char x; cin>>x;
            x-='a';
            a[x].insert(pos);
            s[pos]=x+'a';
        }
        else
        {
            int l,r; cin>>l>>r;
            l--; r--;
            int res=0;
            //cout<<"XD"<<s<<endl;
            for(int i=0;i<26;i++)
            {
                if(a[i].lower_bound(l)==a[i].end()) continue;
                int akt=*a[i].lower_bound(l);
                if(akt<=r) res++;
            }
            cout<<res<<"\n";
        }
    }
    return 0;
}