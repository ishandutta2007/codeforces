#include <bits/stdc++.h>
using namespace std;
 
long long r[100000];
long long g[100000];
long long b[100000];
 
int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int nr,ng,nb;
        scanf("%d %d %d",&nr,&ng,&nb);
        for(int i=0;i<nr;i++) {
            scanf("%lld",&r[i]);
        }
        for(int i=0;i<ng;i++) {
            scanf("%lld",&g[i]);
        }
        for(int i=0;i<nb;i++) {
            scanf("%lld",&b[i]);
        }
        sort(r,r+nr);
        sort(g,g+ng);
        sort(b,b+nb);
        long long ret=4e18;
        for(int i=0;i<nr;i++) {
            auto ig=lower_bound(g,g+ng,r[i]);
            auto ib=upper_bound(b,b+nb,r[i]);
            if (ib-b!=0) {
                ib--;
            }
            if (ig==g+ng) {
                ig--;
            }
            long long rv=r[i];
            long long gv=(*ig);
            long long bv=(*ib);
            ret=min(ret,(rv-gv)*(rv-gv)+(gv-bv)*(gv-bv)+(bv-rv)*(bv-rv));
            auto ig1=upper_bound(g,g+ng,r[i]);
            auto ib1=lower_bound(b,b+nb,r[i]);
            if (ig1-g!=0) {
                ig1--;
            }
            if (ib1==b+nb) {
                ib1--;
            }
            rv=r[i];
            gv=(*ig1);
            bv=(*ib1);
            ret=min(ret,(rv-gv)*(rv-gv)+(gv-bv)*(gv-bv)+(bv-rv)*(bv-rv));
        }
        for(int i=0;i<ng;i++) {
            auto ir=lower_bound(r,r+nr,g[i]);
            auto ib=upper_bound(b,b+nb,g[i]);
            if (ib-b!=0) {
                ib--;
            }
            if (ir==r+nr) {
                ir--;
            }
            long long rv=(*ir);
            long long gv=g[i];
            long long bv=(*ib);
            ret=min(ret,(rv-gv)*(rv-gv)+(gv-bv)*(gv-bv)+(bv-rv)*(bv-rv));
            auto ir1=upper_bound(r,r+nr,g[i]);
            auto ib1=lower_bound(b,b+nb,g[i]);
            if (ir1-r!=0) {
                ir1--;
            }
            if (ib1==b+nb) {
                ib1--;
            }
            rv=(*ir1);
            gv=g[i];
            bv=(*ib1);
            ret=min(ret,(rv-gv)*(rv-gv)+(gv-bv)*(gv-bv)+(bv-rv)*(bv-rv));
        }
        for(int i=0;i<nb;i++) {
            auto ir=lower_bound(r,r+nr,b[i]);
            auto ig=upper_bound(g,g+ng,b[i]);
            if (ig-g!=0) {
                ig--;
            }
            if (ir==r+nr) {
                ir--;
            }
            long long rv=(*ir);
            long long gv=(*ig);
            long long bv=b[i];
            ret=min(ret,(rv-gv)*(rv-gv)+(gv-bv)*(gv-bv)+(bv-rv)*(bv-rv));
            auto ir1=upper_bound(r,r+nr,b[i]);
            auto ig1=lower_bound(g,g+ng,b[i]);
            if (ir1-r!=0) {
                ir1--;
            }
            if (ig1==g+ng) {
                ig1--;
            }
            rv=(*ir1);
            gv=(*ig1);
            bv=b[i];
            ret=min(ret,(rv-gv)*(rv-gv)+(gv-bv)*(gv-bv)+(bv-rv)*(bv-rv));
        }
        printf("%lld\n",ret);
    }
}