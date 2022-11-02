#include <bits/stdc++.h>
using namespace std;
long long n, k, A, B;
vector<int> a;

int less_than_x(int x){
    int d, h, mid;
    d = 0;
    h = k;

    for(int i = 0; i<31; i++){
        mid = (d + h) / 2;
        if(a[mid] < x) d = mid;
        else h = mid;
    }

    return h;
}

long long solve(int offset, int pow){

    long long num = less_than_x(offset + (1 << pow)) - less_than_x(offset);
    if(num == 0) return A;

    else if(pow == 0) return B*num;

    else{
        long long frst, sec;
        frst = solve(offset, (pow - 1));
        sec = solve(offset + (1 << (pow - 1)), pow - 1);
        return min(num * (1 << pow) * B, frst + sec);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   cin >> n >> k >> A >> B;
   a.resize(k + 1);
   for(int i = 0; i<k; i++){
    cin >> a[i];
   }
   a[k] = 2e9;

   sort(a.begin(), a.end());
   cout << solve(1, n);
}