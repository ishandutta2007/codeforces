#include <bits/stdc++.h>
using namespace std;
int a[300001];
int main() {
    int n;cin>>n;
    string s;cin>>s;
    int cnt1=0;
    n=(int)s.size();
    for (int i=0;i<n;i++){
        if (s[i]=='(') a[i+1]=1;
        else if (s[i]==')') a[i+1]=-1;
        else cnt1++;
    }
    int sn=0;
    for (int i=1;i<=n;i++) sn+=a[i];
    if (n%2){
        cout<<":(";
        return 0;
    }
    if (cnt1<abs(sn)){
        cout<<":(";
        return 0;
    }
    int k=(cnt1-sn)/2;
    int cnt=0;
    for (int i=1;i<=n;i++){
        if (a[i]!=0) continue;
        cnt++;
        if (cnt<=k) a[i]=1;
        else a[i]=-1;
    }
    int sum=0;
    for (int i=1;i<n;i++){
        sum+=a[i];
        if (sum<=0){
        cout<<":(";
        return 0;
        }
    }
    sum+=a[n];
    if (sum!=0){
        cout<<":(";
        return 0;
    }
    string str="";
    for (int i=1;i<=n;i++){
        if (a[i]==0) return 1;
        if (a[i]==1) str+="(";
        else if (a[i]==-1) str+=")";
        else return 1;
    }
    cout<<str;
    return 0;
}
/*

*/