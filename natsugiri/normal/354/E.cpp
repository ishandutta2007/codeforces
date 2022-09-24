#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

vector<int>luc, digit[6];
bool carry[30][10];
vector<int>ans;


int rec(LL N, int cnt) {
    if (N==0) {
	if (carry[cnt][0]) return 0;
	return -1; // no answer
    }

    for (int i=0; i<10; i++) {
	if (!carry[cnt][i]) continue;
	for (int j=0; j<(int)luc.size(); j++) {
	    if (N%10 == (i+luc[j])%10)
		carry[cnt+1][(i+luc[j])/10] = true;
	}
    }

    int tmp = rec(N/10, cnt+1);
    //printf("(%d %lld)", tmp, N);
    if(tmp==-1) return -1;

    for (int i=0; i<10; i++) {
	if (!carry[cnt][i]) continue;
	for (int j=0; j<(int)luc.size(); j++) {
	    if (N%10 == (i+luc[j])%10 && (i+luc[j])/10 == tmp) {
		ans.push_back(j);
		return i;
	    }
	}
    }

    return -1;
}


int main() {
    int T; LL N;
    scanf("%d", &T);
    for (int z=0; z<=6; z++) {
	for (int f=0; f+z<=6; f++) {
	    int s=6-f-z;
	    luc.push_back(4*f + 7*s);
	    for (int k=0; k<6; k++) {
		if (k<z) digit[k].push_back(0);
		else if (k<f+z) digit[k].push_back(4);
		else digit[k].push_back(7);
	    }
	}
    }


    for (;T--;) {
	cin >> N;
	ans.clear();
	memset(carry, 0, sizeof carry);
	carry[0][0] = true;

	int tmp = rec(N, 0);
	if (tmp != -1) {
	    LL out[6]={};
	    for (int i=0; i<(int)ans.size(); i++) {
		for (int k=0; k<6; k++)
		    out[k] = out[k]*10 + digit[k][ans[i]];
	    }
	    for (int k=0; k<6; k++) {
		cout << out[k];
		putchar(k==5 ? '\n' : ' ');
	    }
	} else {
	    puts("-1");
	}
    }
    return 0;
}