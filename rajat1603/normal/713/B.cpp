#include "bits/stdc++.h"
using namespace std;
int n;
void ask(int a , int b , int c , int d){
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
    fflush(stdout);
}
int find(int x1 , int y1 , int x2 , int y2 , int val , int &ansx1 , int &ansy1 , int &ansx2 , int &ansy2){
    if(x1 > x2 || y1 > y2){
        return 0;
    }
    ask(x1 , y1 , x2 , y2);
    int ret;
    cin >> ret;
    if(!ret){
        return 0;
    }
    int l = y1;
    int r = y2;
    while(l < r){
        int mid = l + r >> 1;
        ask(x1 , y1 , x2 , mid);
        int ret;
        cin >> ret;
        if(ret >= val){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    int maxr = r;
    l = y1;
    r = maxr;
    while(l < r){
        int mid = l + r + 1 >> 1;
        ask(x1 , mid , x2 , maxr);
        int ret;
        cin >> ret;
        if(ret >= val){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    int maxl = l;
    l = x1;
    r = x2;
    while(l < r){
        int mid = l + r >> 1;
        ask(x1 , maxl , mid , maxr);
        int ret;
        cin >> ret;
        if(ret >= val){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    int maxb = r;
    l = x1;
    r = maxb;
    while(l < r){
        int mid = l + r + 1 >> 1;
        ask(mid , maxl , maxb , maxr);
        int ret;
        cin >> ret;
        if(ret >= val){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    int maxt = r;
    ansx1 = maxt;
    ansy1 = maxl;
    ansx2 = maxb;
    ansy2 = maxr;
    return 1;
}
void solve(){
    int ax1 , ay1 , ax2 , ay2;
    find(1 , 1 , n , n , 1 , ax1 , ay1 , ax2 , ay2);
    int aa , bb , cc , dd;
    if(!find(1 , 1 , ax1 - 1 , n , 1 , aa , bb , cc , dd)){
        if(!find(ax2 + 1 , 1 , n , n , 1 , aa , bb , cc , dd)){
            if(!find(1 , 1 , n , ay1 - 1 , 1 , aa , bb , cc , dd)){
                find(1 , ay2 + 1 , n , n , 1 , aa , bb , cc , dd);
            }
        }
    }
    cout << "! " << ax1 << " " << ay1 << " " << ax2 << " " << ay2 << " " << aa << " " << bb << " " << cc << " " << dd << endl;
    fflush(stdout);
}
int main(){
    cin >> n;
    solve();
}