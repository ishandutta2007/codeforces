#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long LL;

LL N, M;

vector<LL> factor(LL n) {
    vector<LL>r;
    for (LL i=1; i*i<n; i++) {
	if (n%i==0) {
	    r.push_back(i);
	}
    }
    sort(r.begin(), r.end());
    return r;
}
int main() {
    cin>>N;
    if (N%3==0) {
	M=N/3;
	vector<LL>f=factor(M);
	LL ans=0;
	for (int i=1; i<int(f.size()); i++) {
	    LL p=M/f[i];
	    for (LL a=1; a<f[i]; a++) {
		LL y=p-a*a-a*f[i];
		if (y<0) break;
		if (y<a) break;
		LL d=f[i]*f[i]-4*y;
		if (d<0) continue;
		LL b=(f[i]+sqrt(f[i]*f[i]-4*y)+0.5)/2, c=f[i]-b;
		if (b*c==y) {
		    if (a<=b && a<=c) {
			if (a==b && a==c) ans++;
			else if (a==b || b==c || c==a) ans+=3;
			else ans+=6;
		    } else {
			break;
		    }
		}
		//if (b*c==y) printf("%lld %lld %lld\n", a, b, c);
	    }
	}
	cout<<ans<<endl;
    } else {
	puts("0");
    }

    return 0;
}