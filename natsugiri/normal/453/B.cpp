#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;


const int MAX = 60;
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
int GCD[MAX][MAX];

int N;
int A[111], B[111];
int cnt;
int best;
vector<int>ans;
pair<int,int> A_sort[111];

vector<int> v;
void rec(int p) {
    if (p == MAX) {
        int tmp = 0;
        int i, j;
        for (i=j=0; i<N-(int)v.size(); i++, j++) tmp += A_sort[j].first - 1;
        for (i=0; i<(int)v.size(); i++, j++) tmp += abs(A_sort[j].first-v[i]);

        if (best > tmp) {
            ans = v;
            best = tmp;
        }
        cnt++;
        return;
    }

    rec(p+1);
    for (int i=0; i<(int)v.size(); i++) {
        if (GCD[v[i]][p] != 1) return;
    }
    v.push_back(p);
    rec(p+1);
    v.pop_back();
}

int main() {

    for (int i=1; i<MAX; i++) {
        for (int j=1; j<MAX; j++) {
            GCD[i][j] = gcd(i, j);
        }
    }
    
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", A+i);
    for (int i=0; i<N; i++) best += A[i]-1;
    for (int i=0; i<N; i++) A_sort[i] = make_pair(A[i], i);
    sort(A_sort, A_sort+N);

    rec(2);


    {
        int i, j;
        for (i=j=0; i<N-(int)ans.size(); i++, j++) B[A_sort[j].second] = 1;
        for (i=0; i<(int)ans.size(); i++, j++) B[A_sort[j].second] = ans[i];
    }

    for (int i=0; i<N; i++) {
        printf("%d%c", B[i], i==N-1 ? '\n' : ' ');
    }

    //cerr << cnt << endl;
    return 0;
}