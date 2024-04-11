#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int P = 1 << 19;
const int K = 19;
int n , m , k;
char s[N];
char t[N];
int sum[N];
int answer;

int rev[P];
void pre(){
    int res;
    for(int i = 0 ; i < P ; ++i){
        res = 0;
        for(int j = 0 ; j < K ; ++j){
            if((i >> j) & 1){
                res |= 1 << (K - j - 1);
            }
        }
        rev[i] = res;
    }
}

const double pi = acos(-1.0);

struct base{
    double x , y;
    base(){
        x = 0;
        y = 0;
    }
    base(double _x , double _y){
        x = _x;
        y = _y;
    }
    inline base operator + (const base &o) const {
        return base(x + o.x , y + o.y);
    }
    inline base operator - (const base &o) const {
        return base(x - o.x , y - o.y);
    }
    inline base operator * (const base &o) const {
        return base(x * o.x - y * o.y , x * o.y + y * o.x);
    }
};

base a[P];
base b[P];
base c[P];

void fft(base a[] , bool inv){
    for(int i = 0 ; i < P ; ++i){
        if(rev[i] > i){
            swap(a[i] , a[rev[i]]);
        }
    }
    for(int size = 2 ; size <= P ; size <<= 1){
        int m = size >> 1;
        base w(cos(2 * pi / size) , sin(2 * pi / size) * (inv ? -1 : 1));
        for(int i = 0 ; i < P ; i += size){
            base cur(1 , 0);
            for(int j = 0 ; j < m ; ++j){
                base v = a[i + j];
                base u = a[i + j + m] * cur;
                a[i + j] = v + u;
                a[i + j + m] = v - u;
                cur = cur * w;
            }
        }
    }
}

void solve(char c){
    for(int i = 0 ; i < P ; ++i){
        a[i] = base();
        b[i] = base();
    }
    for(int i = 0 ; i < m ; ++i){
        if(t[i] == c){
            b[i] = base(1 , 0);
        }
    }
    int last = -N;
    for(int i = 0 ; i < n ; ++i){
        if(s[i] == c){
            last = i;
        }
        if(i - last <= k){
            a[i] = base(1 , 0);
        }
    }
    last = N + N;
    for(int i = n - 1 ; i >= 0 ; --i){
        if(s[i] == c){
            last = i;
        }
        if(last - i <= k){
            a[i] = base(1 , 0);
        }
    }
    fft(a , 0);
    fft(b , 0);
    for(int i = 0 ; i < P ; ++i){
        ::c[i] = a[i] * b[i];
    }
    fft(::c , 1);
    for(int i = 0 ; i + m - 1 < n ; ++i){
        int idx = n - i - 1;
        sum[i] += ((long long)(::c[idx].x / P + 0.5));
    }
}

int main(){
    scanf("%d %d %d" , &n , &m , &k);
    scanf("%s" , s);
    reverse(s , s + n);
    scanf("%s" , t);
    pre();
    solve('A');
    solve('T');
    solve('G');
    solve('C');
    for(int i = 0 ; i + m <= n ; ++i){
        answer += sum[i] == m;
    }
    printf("%d\n" , answer);
}