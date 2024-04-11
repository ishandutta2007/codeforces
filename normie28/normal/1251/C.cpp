#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,n,m,i,j,k,t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    vector<long long> odd,even;
    string s; char c;
    for (k=1;k<=t;k++)
    {
        odd.clear();
        even.clear();
        cin>>s; n=s.length();
        for (i=0;i<n;i++)
        {
            a=s[i]-48;
            if (a%2) odd.push_back(a); else even.push_back(a);
        }
        n=odd.size();
        m=even.size();
        i=0;j=0;
        while ((i<n)or(j<m)) if (i==n) {c=even[j]+48; cout<<c; j++;} else if (j==m)
            {
                c = odd[i] + 48;
                cout << c;
                i++;
            }
            else if (odd[i] < even[j])
            {
                c = odd[i] + 48;
                cout << c;
                i++;
            }
            else
            {
                c = even[j] + 48;
                cout << c;
                j++;
            }
            cout<<endl;
    }
}