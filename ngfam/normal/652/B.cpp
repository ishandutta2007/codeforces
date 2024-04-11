#include<bits/stdc++.h>
using namespace std;
const int maxN=1e3+1;
int A[maxN],n,g;
vector<int> MAX,MIN;
void enter(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>A[i];
}
bool ss(int a,int b){
    return (a>b);
}
void init(){
    g=(n+1)/2;
    sort(A+1,A+n+1);
    for(int i=1;i<=g;i++)MIN.push_back(A[i]);
    for(int i=g+1;i<=n;i++)MAX.push_back(A[i]);
    sort(MAX.begin(),MAX.end(),ss);
}
void solve(){
    if(MAX.size()<MIN.size()){
        for(int i=0;i<MAX.size();i++)cout<<MIN[i]<<" "<<MAX[i]<<" ";
        cout<<MIN[g-1]<<" ";
    }
    else {
        for(int i=0;i<MAX.size();i++)cout<<MIN[i]<<" "<<MAX[i]<<" ";
    }
}
int main(){
    enter();
    init();
    solve();
}