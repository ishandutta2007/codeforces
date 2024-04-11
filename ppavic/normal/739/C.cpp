#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int llint;

const int N = 3e5 + 500;
const int off = 1 << 19;

struct node{
    llint l,r;
    int mil,mir;
    int mxl,mxr;
    int sol;
    int sl,sr,len;
};

int n;
int q,a,b;
llint c,x;

node tour[3 * off];
llint prop[3*off];

node mrg(node A,node B){
    if(A.sol == -1) return B;
    if(B.sol == -1) return A;
    node C;
    C.l = A.l;
    C.r = B.r;
    C.mil = A.mil;
    if(A.mil == A.len){
        if(A.r < B.l){
            C.mil += B.mil;
        }
    }
    C.mxl = A.mxl;
    if(A.mxl == A.len){
        if(A.r > B.l){
            C.mxl += B.mxl;
        }
    }

    C.mir = B.mir;
    if(B.mir == B.len){
        if(A.r > B.l){
            C.mir += A.mir;
        }
    }
    C.mxr = B.mxr;
    if(B.mxr == B.len){
        if(A.r < B.l){
            C.mxr += A.mxr;
        }
    }
    C.sl = max(A.sl,max(C.mxl,C.mil));
    // POINJE
    if(A.mil == A.len && A.r < B.l){
        C.sl = max(C.sl,A.mil + B.sl);
    }
    // ZAVRAVA
    if(A.sl == A.len && A.r > B.l){
        C.sl = max(C.sl,A.sl + B.mxl);
    }
    if(A.mil == A.len && A.r != B.l){
        C.sl = max(C.sl,A.mil + B.mxl);
    }
    C.sr = max(B.sr,max(C.mxr,C.mir));
    if(B.mir == B.len && A.r > B.l){
        C.sr = max(C.sr,B.mir + A.sr);
    }
    if(B.sr == B.len && B.l > A.r){
        C.sr = max(C.sr, B.sr + A.mxr);
    }
    if(B.mir == B.len && B.l != A.r){
        C.sr = max(C.sr, B.mir + A.mxr);
    }
    C.sol = max(A.sol,B.sol);
    if(A.r != B.l){
        C.sol = max(C.sol,A.mxr+ B.mxl);
    }
    if(A.r > B.l){
        C.sol = max(C.sol,A.sr + B.mxl);
    }
    if(A.r < B.l){
        C.sol = max(C.sol,A.mxr + B.sl);
    }
    C.sol = max(max(C.sl,C.sr),C.sol);
    C.len = A.len + B.len;
    return C;
}

void refresh(int i){
    if(!prop[i]) return;
    tour[i].l += prop[i];
    tour[i].r += prop[i];
    if( i < off) {
        prop[2*i]   += prop[i];
        prop[2*i+1] += prop[i];
    }
    prop[i] = 0;
}

void update(int i,int a,int b,int lo,int hi,llint x){
    refresh(i);
    if(lo <= a && b <= hi){
        prop[i] = x;
        refresh(i);
        return;
    }
    if(b < lo || a > hi) return;
    update(2*i,a,(a+b)/2,lo,hi,x);
    update(2*i+1,(a+b)/2+1,b,lo,hi,x);
    tour[i] = mrg(tour[2*i],tour[2*i+1]);
}



int main(){
    scanf("%d",&n);
    for(int i = 0;i<2 * off;i++){
        tour[i+off].sol = -1;
    }
    for(int i = 0;i<n;i++){
        scanf("%I64d",&x);
        tour[i+off].l = x;
        tour[i+off].r = x;
        tour[i+off].mil = 1;
        tour[i+off].mir = 1;
        tour[i+off].mxl = 1;
        tour[i+off].mxr = 1;
        tour[i+off].sl = 1;
        tour[i+off].sr = 1;
        tour[i+off].sol = 1;
        tour[i+off].len = 1;
    }
    for(int i = off-1;i>0;i--){
        tour[i] = mrg(tour[2*i],tour[2*i+1]);
        if(tour[i].sol == -1) continue;
    };
    scanf("%d",&q);
    for(int i = 0;i<q;i++){
        scanf("%d%d%I64d",&a,&b,&c);
        a--;b--;
        update(1,0,off-1,a,b,c);
        printf("%d\n",tour[1].sol);
    }

}

/**
90
571 783 575 344 222 247 770 558 765 228 741 964 867 686 319 381 30 657 518 558 106 885 522 210 78 95 923 295 220 590 549 383 669 382 411 656 171 840 978 740 822 72 481 794 400 654 663 923 441 982 861 710 515 128 376 892 118 632 809 884 510 223 252 912 640 808 924 223 825 884 381 241 127 703 457 182 685 584 140 223 212 413 248 963 380 573 98 180 335 668
1
54 58 613695634

**/