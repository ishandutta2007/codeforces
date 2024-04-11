#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


typedef long long LL;

vector<int>prime;
vector<int> make_prime(int n) {
    vector<int>r(n); r[0]=r[1]=0;
    for (int i=2; i<n; i++) r[i]=i;
    for (int i=2; i*i<n; i++) {
	if (r[i]) {
	    for (int j=i*i; j<n; j+=i) r[j]=0;
	}
    }
    //r.erase(remove(r.begin(), r.end(), 0), r.end());
    return r;
}
int a, b, k;
int main() {
    prime=make_prime(1000100);
    scanf("%d%d%d", &a, &b, &k);
    int l=a, r, ans=-1, cnt=0;
    for (r=a; cnt<k && r<=b; r++) {
	if (prime[r]) cnt++;
    }
    r--;
    if (cnt<k) { puts("-1"); }
    else {
	ans=r-l+1;
	for (r++; r<=b; r++) {
	    if (prime[r]) {
		for (; prime[l]==0; l++) ;
		l++;
	    } else if (prime[l]==0) l++;
	    //printf("%d %d\n", l, r);
	    ans=max(ans, r-l+1);
	}
	    
	printf("%d\n", ans);
    }
    
    return 0;
}