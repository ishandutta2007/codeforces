#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

char buf[999];
int main() {

    scanf("%s", buf);
    int len = strlen(buf);
    char C = buf[len-1];
    LL N;
    buf[len-1] = 0;
    sscanf(buf, "%lld", &N);
    N--;

    LL ans = 0;
    LL r = N / 4;
    N -= r * 4;

    ans += 16 * r;
    if (N & 1) ans += 7;

    if (0) ;
    else if (C == 'f') ans+=1;
    else if (C == 'e') ans+=2;
    else if (C == 'd') ans+=3;
    else if (C == 'a') ans+=4;
    else if (C == 'b') ans+=5;
    else if (C == 'c') ans+=6;

    printf("%lld\n", ans);


    return 0;
}