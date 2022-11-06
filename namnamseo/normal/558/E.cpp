#include <cstdio>

int buck=0;

int cnt[400][26];

int size[400];

bool usort[400];
bool dsort[400];

char dat[400][400];

char all[100010];
int len;
int bn;

int cc[26];

bool chk[400];

int pick_kth(int ind,int k){
    int i;
    for(i=0;i<26;++i){
        k-=cnt[ind][i];
        if(k<0) break;
    }
    return i;
}

int min(int a,int b){ return a>b?b:a; }

void reset(int ind,int up){
    int i,k,j=0;
    if(up){
        for(i=0;i<26;++i) for(k=0;k<cnt[ind][i];++k) dat[ind][j++]=i;
    } else {
        for(i=25;0<=i;--i) for(k=0;k<cnt[ind][i];++k) dat[ind][j++]=i;
    }
}

int main()
{
    int i,q;
    scanf("%d%d",&len,&q);
    while(buck*buck<len) ++buck;
    scanf("%s",all);
    int ci=-1;
    for(i=0;i<len;++i){
        if(!(i%buck)) ++ci;
        ++cnt[ci][all[i]-'a'];
        ++size[ci];
        dat[ci][i%buck]=all[i]-'a';
        //printf("%d, %d : %d\n",ci,i%buck,all[i]-'a');
    }
    int l,r,up;
    int orl, orr;
    int j;
    for(;q--;){
        scanf("%d%d%d",&l,&r,&up);
        //puts("\non query");
        --l; --r;
        orl=l; orr=r;
        for(i=0;i<26;++i) cc[i]=0;
for(i=0;i<400;++i) chk[i]=false;
        ci=l/buck;
        while(l<=r){
            if(!(l%buck) && l+buck-1<=r){
                for(i=0;i<26;++i) cc[i]+=cnt[ci][i];
                ++ci;
                l+=buck;
            } else {
                //printf("Naive count %d : ind %d\n",l,l%buck);
                if(usort[ci]){
                    ++cc[pick_kth(ci,l%buck)];
                } else if(dsort[ci]){
                    ++cc[pick_kth(ci,size[ci]-l%buck-1)];
                } else {
                    //printf("naive %d,%d -> %d\n",ci,l%buck,dat[ci][l%buck]);
                    ++cc[dat[ci][l%buck]];
                }
                ++l;
                if(!(l%buck)) ++ci;
            }
        }
        l=orl; r=orr;
        ci=l/buck;
        while(l<=r){
            if(!(l%buck) && l+buck-1<=r){
                l+=buck; ++ci;
            } else {
                if(!chk[ci] && (usort[ci] || dsort[ci])) chk[ci]=true, reset(ci,usort[ci]);
                ++l;
                if(!(l%buck)) ++ci;
            }
        }
        //for(i=0;i<26;++i) if(cc[i]) printf("There are %c : %d\n",i+'a',cc[i]);
        l=orl; r=orr;
        ci=l/buck;
        while(l<=r){
            if(!(l%buck) && l+buck-1<=r){
                for(i=0;i<26;++i) cnt[ci][i]=0;
                int asdf=size[ci];
                if(up){
                    for(i=0;i<26;++i){
                        cnt[ci][i]=min(asdf,cc[i]);
                        cc[i]-=cnt[ci][i];
                        asdf -=cnt[ci][i];
                    }
                    usort[ci]=true;
                    dsort[ci]=false;
                } else {
                    for(i=25;0<=i;--i){
                        cnt[ci][i]=min(asdf,cc[i]);
                        cc[i]-=cnt[ci][i];
                        asdf -=cnt[ci][i];
                    }
                    dsort[ci]=true;
                    usort[ci]=false;
                }
                ++ci;
                l+=buck;
            } else {
                //printf("Naive Appl")
                if(up) { for(i=0;i<26;++i) if(cc[i]) break; }
                else   { for(i=25;0<=i;--i) if(cc[i]) break; }
                --cnt[ci][dat[ci][l%buck]];
                dat[ci][l%buck]=i;
                ++cnt[ci][i];
                --cc[i];
usort[ci]=dsort[ci]=false;
                ++l;
                if(!(l%buck)) ++ci;
                
            }
        }
    }
    for(i=0;i*buck<len;++i){
        if(usort[i]){
            for(j=0;j<26;++j) for(int k=0;k<cnt[i][j];++k) putchar('a'+j);
        } else if(dsort[i]){
            for(j=25;0<=j;--j) for(int k=0;k<cnt[i][j];++k) putchar('a'+j);
        } else {
            for(j=0;j<size[i];++j) putchar('a'+dat[i][j]);
        }
    }
    putchar(10);
    return 0;
}