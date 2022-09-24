#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

#define MAX 10000000
int n, m;
int A[100010], B[100010];
int cnt[MAX];
vector<pair<int,int> >a, b;

typedef long long LL;

vector<int>prime;
void make_prime() {
    prime=vector<int>(4000);
    for (int i=0; i<4000; i++) prime[i]=i;
    prime[1]=0;
    for (int i=2; i*i<4000; i++) {
        if (prime[i]) {
            for (int j=i*i; j<4000; j+=i) prime[j]=0;
        }
    }
    prime.erase(remove(prime.begin(), prime.end(), 0), prime.end());
}
void add(int n, int t, vector<pair<int, int> >&v) {
    for (int i=0; prime[i]*prime[i]<=n; i++) {
        for (;n%prime[i]==0;) { v.push_back(make_pair(prime[i],t)); n/=prime[i]; }
    }
    if (n>1) v.push_back(make_pair(n, t));
}

void show(const int v[], int n) {
    for (int i=0; i<n; i++) printf("%d%c", v[i], i==n-1?'\n':' ');
}

int main() {
    make_prime();
    scanf("%d%d", &n, &m);
    int t;
    for (int i=0; i<n; i++) { scanf("%d", A+i); add(A[i], i, a); }
    for (int i=0; i<m; i++) { scanf("%d", B+i); add(B[i], i, b); }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int p, q;
    p=q=0;
    for (;p<(int)a.size() && q<(int)b.size();) {
        if (a[p].first==b[q].first) {
            A[a[p].second]/=a[p].first;
            B[b[q].second]/=b[q].first;
            p++; q++;
        } else if (a[p].first>b[q].first) { q++; }
        else { p++; }
    }
    printf("%d %d\n", n, m);
    show(A, n); show(B, m);

    return 0;
}