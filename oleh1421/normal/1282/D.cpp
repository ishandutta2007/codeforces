#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<"a"<<endl;
    int n;cin>>n;
    if (n==0){
        return 0;
    }
    if (n==300){
        for (int i=1;i<=n;i++) cout<<"b";
        return 0;
    }
    n++;
    string s="";
    for (int i=1;i<=n;i++) s+='a';
    cout<<s<<endl;
    int x;cin>>x;
    if (x>=n) {
        n--;
        for (int i=1;i<=n;i++) cout<<"b";
        cout<<endl;
        int ok;cin>>ok;
        return 0;
    }
    int last=x;
    for (int i=0;i<n;i++){
        s[i]='b';
        cout<<s<<endl;
        int cur;cin>>cur;
        if (!cur) return 0;
        if (cur>last){
            s[i]='a';
        } else last=cur;
    }
    cout<<s<<endl;
    int ok;cin>>ok;


    return 0;
}