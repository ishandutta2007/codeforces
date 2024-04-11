#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, M;
vector<int>ciel, jiro_A, jiro_D;;

int main() {
    scanf("%d%d", &N, &M);
    for (int i=0; i<N; i++) {
	char str[16]; int x;
	scanf("%s %d", str, &x);
	if (str[0]=='A') jiro_A.push_back(x);
	else jiro_D.push_back(x);
    }
    for (int i=0; i<M; i++) {
	int x;
	scanf("%d", &x);
	ciel.push_back(x);
    }

    sort(jiro_A.begin(), jiro_A.end());
    sort(jiro_D.begin(), jiro_D.end());
    sort(ciel.begin(), ciel.end());

    int ans=0;
    for (int s=1; s<=int(jiro_A.size()) && s<=int(ciel.size()); s++) {
	bool ok=true;
	int sum=0;
	for (int i=0; i<s; i++) {
	    if (ciel[M-s+i]<jiro_A[i]) ok=false;
	    sum += ciel[M-s+i]-jiro_A[i];
	}
	if (ok) ans=max(ans, sum);
    }

    { // kill all
	int a=0, b=0;
    

	bool ok=true;
	int sum=0;
	vector<int>r;
	for (;a<int(jiro_D.size()) && b<M;) {
	    if (jiro_D[a]<ciel[b]) { a++; b++; }
	    else { r.push_back(ciel[b]); b++; }
	}
	if (a<int(jiro_D.size())) ok=false;

	for (;b<M; b++) r.push_back(ciel[b]);
	
	a=b=0;
	for (;a<int(jiro_A.size()) && b<int(r.size());) {
	    if (jiro_A[a]<=r[b]) {
		sum += r[b]-jiro_A[a];
		a++; b++;
	    } else {
		sum += r[b];
		b++;
	    }
	}
	if (a<int(jiro_A.size())) ok=false;
	for (;b<int(r.size()); b++) sum += r[b];
	if (ok) ans = max(ans, sum);
    }
    
    printf("%d\n", ans);

    return 0;
}