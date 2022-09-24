#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int N, d[111], m;
vector<int>v;

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", d+i);
    sort(d, d+N);

    if (d[0]==0) v.push_back(0);

    for (int i=0; i<N; i++) {
	if (0<d[i] && d[i]<10) {
	    v.push_back(d[i]);
	    m+=1;
	    break;
	}
    }
    for (int i=0; i<N; i++) {
	if (9<d[i] && d[i]<100 && d[i]%10==0) {
	    v.push_back(d[i]);
	    m+=2;
	    break;
	}
    }
    if (m==0) {
	for (int i=0; i<N; i++) {
	    if (9<d[i] && d[i]<100) {
		v.push_back(d[i]);
		break;
	    }
	}
    }

    for (int i=0; i<N; i++) {
	if (d[i]==100) {
	    v.push_back(d[i]);
	    break;
	}
    }
			
    printf("%d\n", v.size());
    for (int i=0; i<int(v.size()); i++) {
	printf("%d\n", v[i]);
    }
    return 0;
}