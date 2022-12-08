#include<bits/stdc++.h>
#define int long long
using namespace std;
int ask(int l, int r){
    cout<<"? "<<l<<" "<<r<<endl;
    int x;
    cin>>x;
    return x;
}
main(){
    int n;
    cin >> n;
    int x = ask(1, n);
    if(x > 1 && ask(1,x) == x){
        int l = 1, r = x-1;
        while(l < r){
            int mid = (l + r + 1)/2;
            if(ask(mid, x) == x) l = mid;
            else r = mid - 1;
        }
        cout<<"! "<<l<<endl;
    }
    else{
        int l = x+1, r = n;
        while(l < r){
            int mid = (l + r )/2;
            if(ask(x, mid) == x) r = mid;
            else l = mid + 1;
        }
        cout<<"! "<<l<<endl;
    }



}