#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, M, MA,MI;

int main() {
    scanf("%d%d%d%d", &N, &M, &MI, &MA);
    bool ok = true, bma = false, bmi = false;
    for (int i=0; i<M; i++) {
	int t;
	scanf("%d", &t);
	if (t < MI || MA < t) ok = false;
	if (t == MI) bmi = true;
	if (t == MA) bma = true;
    }

    if (!bma) M++;
    if (!bmi) M++;
    if (M > N) ok = false;
    puts(ok ? "Correct" : "Incorrect");
	

    return 0;
}