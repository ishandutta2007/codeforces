#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){

    int n;cin>>n;
    int cnt1=0;
    int cnt2=0;
    int cnt3=0;
    for (int i=0;i<n;i++){
        int a;cin>>a;
        if (a>0) cnt1++;
        else if (a<0) cnt2++;
        else cnt3++;
    }
    int h=n/2+n%2;
    if (cnt1<h && cnt2<h){
        cout<<0;
        return 0;
    }
    if (cnt1<h){
        cout<<-1;
        return 0;
    }
    cout<<1;
    return 0;
}