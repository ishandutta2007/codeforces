#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

typedef long long LL;

int N, D;
int A[111], X[111], Y[111];
LL life[111];

LL cost(int i, int j) {
    return LL(D)*(abs(X[i]-X[j])+abs(Y[i]-Y[j]));
}

int main() {
    scanf("%d%d", &N, &D);
    for (int i=1; i<N-1; i++) scanf("%d", A+i);
    for (int i=0; i<N; i++) scanf("%d%d", X+i, Y+i);
    
    LL l=-1, r=1LL<<40, m;
    for (;r-l>1;) {
	//cout<<r<<endl;
	m=(r+l)/2;

	memset(life, -1, sizeof life);

	life[0]=m;
	priority_queue<pair<LL,int> >Q;
	Q.push(make_pair(m, 0));
	
	for (;!Q.empty();) {
	    pair<LL,int>e=Q.top(); Q.pop();
	    if (e.second==N-1) break;
	    for (int i=0; i<N; i++) {
		if (i==e.second) continue;
		LL c=cost(e.second, i);
		if (c<=e.first && life[i]<A[i]+e.first-c) {
		    life[i]=A[i]+e.first-c;
		    Q.push(make_pair(life[i], i));
		}
	    }
	}
	if (life[N-1]>-1) r=m;
	else l=m;
    }
    cout<<r<<endl;
    return 0;
}