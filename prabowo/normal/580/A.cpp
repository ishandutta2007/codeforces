#include<iostream>
#include<algorithm>
using namespace std;

int n,a,b,ans=1,cur=1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> a;
    for(int i=1; i<n; i++){
        cin >> b;
        if(b<a){ans=max(ans,cur); cur=1;}
        else cur++;
        a=b;
    }
    cout << max(ans,cur) << endl;
    return 0;
}