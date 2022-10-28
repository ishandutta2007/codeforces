#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
const int K = 20;
const int P = 1 << K;
int t;
int n;
char str[N];
int a[N];
int b[N];
int c[P];
bool rip[N];

int rev[P];
void pre(int K){
	int P = 1 << K;
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

base aa[P];
base bb[P];
base cc[P];

void fft(base a[] , bool inv , int K){
	int P = 1 << K;
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

void mult(){
	int k = 0;
	while((1 << k) <= (n + n)){
		++k;
	}
	int nn = 1 << k;
	for(int i = 0 ; i < nn ; ++i){
		aa[i] = base(0 , 0);
		bb[i] = base(0 , 0);
		cc[i] = base(0 , 0);
	}
	for(int i = 0 ; i <= n ; ++i){
		aa[i].x = a[i];
		bb[i].x = b[i];
	}
	pre(k);
	fft(aa , 0 , k);
	fft(bb , 0 , k);
	for(int i = 0 ; i < nn ; ++i){
		cc[i] = aa[i] * bb[i];
	}
	fft(cc , 1 , k);
	for(int i = 0 ; i < nn ; ++i){
		c[i] = (cc[i].x / nn) + 0.5;
	}
}
int main(){
	scanf("%d" , &t);
	while(t--){
		scanf("%d" , &n);
		scanf("%s" , str + 1);
		for(int i = 0 ; i <= n ; ++i){
			a[i] = 0;
			b[i] = 0;
			rip[i] = 0;
		}
		for(int i = 0 ; i <= n + n ; ++i){
			c[i] = 0;
		}
		for(int i = 1 ; i <= n ; ++i){
			if(str[i] == '?'){

			}
			else if(str[i] == 'V'){
				a[i] = 1;
			}
			else{
				b[n - i] = 1;
			}
		}
		mult();
		for(int i = 1 ; i <= n ; ++i){
			if(c[i + n]){
				rip[i] = 1;
			}
		}
		for(int i = 0 ; i <= n ; ++i){
			a[i] = 0;
			b[i] = 0;
		}
		for(int i = 0 ; i <= n + n ; ++i){
			c[i] = 0;
		}
		for(int i = 1 ; i <= n ; ++i){
			if(str[i] == '?'){

			}
			else if(str[i] == 'V'){
				a[n - i] = 1;
			}
			else{
				b[i] = 1;
			}
		}
		mult();
		for(int i = 1 ; i <= n ; ++i){
			if(c[i + n]){
				rip[i] = 1;
			}
		}
		for(int i = n ; i >= 1 ; --i){
			int tot = 0;
			for(int j = i ; j <= n ; j += i){
				tot += rip[j];
			}
			if(tot > 0){
				rip[i] = 1;
			}
		}
		int ans = n;
		for(int i = 1 ; i <= n ; ++i){
			ans -= rip[i];
		}
		printf("%d\n" , ans);
		for(int i = 1 ; i <= n ; ++i){
			if(!rip[i]){
				printf("%d " , i);
			}
		}
		printf("\n");
	}
}