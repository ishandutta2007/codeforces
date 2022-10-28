#include "bits/stdc++.h"
using namespace std;
const int M = 1e6 + 6;
namespace fft{
    const int N = 20;
    const int MAXN = 1 << N;
    const double today = acos(-1.0);
    const double pi = today;
    struct base{
        double x , y;
        base(){
            x = 0;
            y = 0;
        }
        base(double a){
            x = a;
            y = 0;
        }
        base(double a , double b){
            x = a;
            y = b;
        }
        base conj(){
            return base(x , -y);
        }
        base operator = (const base &o){
            x = o.x;
            y = o.y;
            return *this;
        }
        base operator + (const base &o) const {
            return base(x + o.x , y + o.y);
        }
        base operator - (const base &o) const {
            return base(x - o.x , y - o.y);
        }
        base operator * (const base &o) const {
            return base(x * o.x - y * o.y , y * o.x + x * o.y);
        }
        base operator * (const double num) const {
            return base(x * num , y * num);
        }
        base operator / (const double num) const {
            return base(x / num , y / num);
        }

    };
    base w[MAXN];
    base f1[MAXN];
    int rev[MAXN];
    void pre(int k){
        static int rk = -1 , lim;
        if(k == rk){
            return;
        }
        rk = k , lim = 1 << k;
        for(int i = 1 ; i <= lim ; ++i){
            int j = rev[i - 1] , t = k - 1;
            while(t >= 0 && ((j >> t) & 1)){
                j ^= 1 << t;
                --t;
            }
            if(t >= 0){
                j ^= 1 << t;
                --t;
            }
            rev[i] = j;
        }
    }
    void fft(base *a , int k){
        pre(k);
        int n = 1 << k;
        for(int i = 0 ; i < n ; ++i){
            if(rev[i] > i){
                swap(a[i] , a[rev[i]]);
            }
        }
        for(int l = 2 , m = 1 ; l <= n ; l += l , m += m){
            if(w[m].x == 0 && w[m].y == 0){
                double angle = pi / m;
                base ww(cos(angle) , sin(angle));
                if(m > 1){
                    for(int j = 0 ; j < m ; ++j){
                        if(j & 1){
                            w[m + j] = w[m + j >> 1] * ww;
                        }
                        else{
                            w[m + j] = w[m + j >> 1];
                        }
                    }
                }
                else{
                    w[m] = base(1 , 0);
                }
            }
            for(int i = 0 ; i < n ; i += l){
                for(int j = 0 ; j < m ; ++j){
                    base v = a[i + j];
                    base u = a[i + j + m] * w[m + j];
                    a[i + j] = v + u;
                    a[i + j + m] = v - u;
                }
            }
        }
    }
    void mul(vector < int > &a , const vector < int > &b){
        int k = 20;
        int n = 1 << k;
        for(int i = 0 ; i < M ; ++i){
            f1[i] = base(a[i] , b[i]);
        }
        for(int i = M ; i < n ; ++i){
            f1[i] = base(0 , 0);
        }
        fft(f1 , k);
        for(int i = 0 ; i <= (n >> 1) ; ++i){
            base p = f1[i] + f1[(n - i) % n].conj();
            base _q = f1[(n - i) % n] - f1[i].conj();
            base q(_q.y , _q.x);
            f1[i] = (p * q) / 4;
            if(i > 0){
                f1[(n - i)] = f1[i].conj();
            }
        }
        for(int i = 0 ; i < n ; ++i){
            f1[i] = f1[i].conj();
        }
        fft(f1 , k);
        for(int i = 0 ; i < M ; ++i){
            a[i] = min((long long) (f1[i].x / n + 0.5) , 1LL);
        }
    }
};
int n , k;
int inp;
vector < int > poly;
vector < int > res;
int main(){
    scanf("%d %d" , &n , &k);
    poly.resize(M , 0);
    res.resize(M , 0);
    res[0] = 1;
    while(n--){
        scanf("%d" , &inp);
        poly[inp] = 1;
    }
    while(k){
        if(k & 1){
            fft :: mul(res , poly);
        }
        fft :: mul(poly , poly);
        k >>= 1;
    }
    for(int i = 1 ; i < M ; ++i){
        if(res[i]){
            printf("%d " , i);
        }
    }
    printf("\n");
}