#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define f first
#define s second
#define t abs

int lkd(int a,int b){
    if(b==0){
        return a;
    }
    else{
        return lkd(b,a%b);
    }
}

int main(){

    int a,b;
    cin >> a >> b;
    int mx = max(a,b);
    mx = (6-mx)+1;
    int val = 6;
    int d = 0;
    int lk = lkd(val,mx);
    val /= lk;
    mx /= lk;
    cout << mx << "/" << val;
    return 0;
}