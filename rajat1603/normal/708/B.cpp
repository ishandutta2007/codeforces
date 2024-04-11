#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
string str;
int a00 , a01 , a10 , a11;
/*int bit[N];
void update(int idx , int val){
    while(idx < N){
        bit[idx] += val;
        idx += idx & -idx;
    }
}
int query(int idx){
    int res = 0;
    while(idx){
        res += bit[idx];
        idx -= idx & -idx;
    }
    return res;
}
int query(int l , int r){
    return query(r) - query(l - 1);
}*/
int tmpa , tmpb , tmpc , tmpd;
void solveagain(int zero , int one){
    str = "";
    if(1LL * (one + zero) * (one + zero - 1LL) / 2LL != a00 + a01 + a10 + a11){
        return;
    }
    /*memset(bit , 0 , sizeof(bit));
    str = " ";
    for(int i = 0 ; i < zero ; ++i){
        str += "0";
        update(i + 1 , 1);
    }
    for(int i = 0 ; i < one ; ++i){
        str += "1";
    }
    long long tot = 1LL * zero * one;
    for(int i = zero + 1 ; i <= zero + one ; ++i){
        if(tot > a01){
            long long cur = tot;
            long long then = cur - query(1 , i - 1);
        }
    }*/
    long long cur = 0;
    for(int i = 0 ; i < zero ; ++i){
        str += "0";
    }
    int put = 0;
    for(int i = 0 ; i < one ; ++i){
        if(cur + zero <= a01){
            str += "1";
            cur += zero;
            ++put;
        }
        else{
            break;
        }
    }
    if(put == one && cur < a01){
        return;
    }
    int rem = a01 - cur;
    if(rem){
        ++put;
    }
    string newstr = "";
    for(int i = put + 1 ; i <= one ; ++i){
        newstr += "1";
    }
    for(int i = 0 ; i < rem ; ++i){
        newstr += "0";
    }
    if(rem){
        newstr += "1";
    }
    for(int i = rem ; i < zero ; ++i){
        newstr += "0";
    }
    if(rem){
        --put;
    }
    for(int i = 0 ; i < put ; ++i){
        newstr += "1";
    }
    int zerocnt = 0;
    int onecnt = 0;
    for(int i = 0 ; i < newstr.size() ; ++i){
        if(newstr[i] == '1'){
            a11 -= onecnt;
            a01 -= zerocnt;
        }
        else{
            a00 -= zerocnt;
            a10 -= onecnt;
        }
        zerocnt += (newstr[i] == '0');
        onecnt += (newstr[i] == '1');
    }
    if(a00 == 0 && a01 == 0 && a10 == 0 && a11 == 0){
        cout << newstr << endl;
        exit(0);
    }
    a00 = tmpa;
    a01 = tmpb;
    a10 = tmpc;
    a11 = tmpd;
}
int main(){
    cin >> a00 >> a01 >> a10 >> a11;
    tmpa = a00;
    tmpb = a01;
    tmpc = a10;
    tmpd = a11;
    if(max(max(a00 , a01) , max(a10 , a11)) == 0){
        cout << "1\n";
        return 0;
    }
    int zero = -1 , one = -1;
    for(int i = 0 ; i < N ; ++i){
        long long nc2 = 1LL * i * (i - 1LL) / 2LL;
        if(nc2 == a00){
            zero = i;
        }
        if(nc2 == a11){
            one = i;
        }
    }
    if(zero == -1 || one == -1){
        cout << "Impossible\n";
        return 0;
    }
    if(1LL * (one + zero) * (one + zero - 1LL) / 2LL != 0LL + a00 + a01 + a10 + a11){
        if(zero == 1){
            solveagain(0 , one);
        }
        if(one == 1){
            solveagain(zero , 0);
        }
        cout << "Impossible\n";
        return 0;
    }
    /*memset(bit , 0 , sizeof(bit));
    str = " ";
    for(int i = 0 ; i < zero ; ++i){
        str += "0";
        update(i + 1 , 1);
    }
    for(int i = 0 ; i < one ; ++i){
        str += "1";
    }
    long long tot = 1LL * zero * one;
    for(int i = zero + 1 ; i <= zero + one ; ++i){
        if(tot > a01){
            long long cur = tot;
            long long then = cur - query(1 , i - 1);
        }
    }*/
    long long cur = 0;
    for(int i = 0 ; i < zero ; ++i){
        str += "0";
    }
    int put = 0;
    for(int i = 0 ; i < one ; ++i){
        if(cur + zero <= a01){
            str += "1";
            cur += zero;
            ++put;
        }
        else{
            break;
        }
    }
    if(put == one && cur < a01){
        if(zero == 1){
            solveagain(0 , one);
        }
        if(one == 1){
            solveagain(zero , 0);
        }
        cout << "Impossible\n";
        return 0;
    }
    int rem = a01 - cur;
    if(rem){
        ++put;
    }
    string newstr = "";
    for(int i = put + 1 ; i <= one ; ++i){
        newstr += "1";
    }
    for(int i = 0 ; i < rem ; ++i){
        newstr += "0";
    }
    if(rem){
        newstr += "1";
    }
    for(int i = rem ; i < zero ; ++i){
        newstr += "0";
    }
    if(rem){
        --put;
    }
    for(int i = 0 ; i < put ; ++i){
        newstr += "1";
    }
    int zerocnt = 0;
    int onecnt = 0;
    for(int i = 0 ; i < newstr.size() ; ++i){
        if(newstr[i] == '1'){
            a11 -= onecnt;
            a01 -= zerocnt;
        }
        else{
            a00 -= zerocnt;
            a10 -= onecnt;
        }
        zerocnt += (newstr[i] == '0');
        onecnt += (newstr[i] == '1');
    }
    if(a00 == 0 && a01 == 0 && a10 == 0 && a11 == 0){
        cout << newstr << endl;
    }
    else{
        if(zero == 1){
            solveagain(0 , one);
        }
        if(one == 1){
            solveagain(zero , 0);
        }
        cout << "Impossible\n";
    }
}