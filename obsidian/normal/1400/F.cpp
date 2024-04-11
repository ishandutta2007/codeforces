#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int N = 9;
int a[30];
struct tree
{
    tree *ne[N],*fail;
    int ct;
}tr[500100],VD,*root,*Q[500100];
int tn;
void init()
{
    tr[tn=0]=VD;
    root=tr+(tn++);
}
void add(int m)
{
    tree *p=root;
    for(int i=0;i<m;i++)
    {
        if(p->ne[a[i]-1]==NULL)
        {
            tr[tn]=VD;
            p->ne[a[i]-1]=tr+(tn++);
        }
        p=p->ne[a[i]-1];
    }
    p->ct++;
}
void pre()
{
    int i,top,tail;
    tree *p,*q;
   	top=0;tail=0;
	for(i=0;i<N;i++)
	if(root->ne[i]!=NULL)
	{
		Q[++tail]=root->ne[i];
		root->ne[i]->fail=root;
	}
	else root->ne[i]=root;
	while(top<tail)
	{
		p=Q[++top];
		for(i=0;i<N;i++)
		if(p->ne[i]!=NULL)
		{
			q=p->ne[i];
			Q[++tail]=q;
			q->fail=p->fail->ne[i];
			if(q->fail==NULL)q->fail=root;
		}
		else p->ne[i]=p->fail->ne[i];
	}
}

int cnt, cnt2;
void dfs(int re, int pos, int x) {
    if (re == 0) {
        ++cnt;
        bool ok = true;
        for (int i = 0; i < pos; ++i) {
            int s = 0;
            for (int j = i; j < pos; ++j) {
                s += a[j];
                if (s < x && x % s == 0) ok = false;
            }
        }
        if (ok) ++cnt2, add(pos);
        return;
    }
    for (int i = 1; i <= min(9, re); ++i) {
        a[pos] = i;
        dfs(re - i, pos + 1, x);
    }
}

char s[1200];
int dp[1200][5100], K;

int main() {
    for(int i=0;i<N;i++)VD.ne[i]=NULL;VD.ct=0;
    /*
    for (int i = 1; i <= 20; ++i) {
        init();
        cnt = 0;
        cnt2 = 0;
        dfs(i, 0, i);
        printf("%d %d %d %d\n", i, cnt, cnt2, tn);
    }*/
    while (~scanf("%s%d", s, &K)) {
        int n = strlen(s);
        init();
        dfs(K, 0, K);
        pre();
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < tn; ++j) {
                if (dp[i][j] == -1) continue;
                if (dp[i + 1][j] == -1 || dp[i + 1][j] > dp[i][j] + 1) dp[i + 1][j] = dp[i][j] + 1;
                int k = tr[j].ne[s[i] - '1'] - tr;
                if (tr[k].ct == 0) {
                    if (dp[i + 1][k] == -1 || dp[i + 1][k] > dp[i][j]) dp[i + 1][k] = dp[i][j];
                }
            }
        }
        int ans = n + 1;
        for (int j = 0; j < tn; ++j) {
            if (dp[n][j] == -1) continue;
            ans = min(ans, dp[n][j]);
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
116285317
8
314159265359
1
13
13
3434343434
7
*/