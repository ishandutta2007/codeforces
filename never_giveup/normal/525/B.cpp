#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    string s;
    cin>>s;
    int n;
    cin>>n;
    int a[100000];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=1;i<=s.length()/2;i++){
        int l=0,r=n+1;
        while(r-l>1){
            int m=(l+r)/2;
            if(a[m-1]<=i)
                l=m;
            else
                r=m;
        }
        if(l%2==1)
            swap(s[i-1],s[s.length()-i]);
    }
    cout<<s;
}