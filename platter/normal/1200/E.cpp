#include <bits/stdc++.h>
using namespace std;

int a[2]={302,1039};
int mod[2]={1000000007,1000000009};

long long fastpow(long long x,long long y,int type) {
    if (y==0) {
        return 1;
    }
    if (y%2==1) {
        return (fastpow(x,y-1,type)*x)%mod[type];
    }
    long long half=fastpow(x,y/2,type);
    return (half*half)%mod[type];
}

vector<long long> phash[2];
int n;
char tem[1000005];
char str[1000005];
long long sv[2][1000005];
long long rev[2][1000005];
int len;
int save[100005];

int main(void) {
    sv[0][0]=1;
    sv[1][0]=1;
    for(int i=0;i<2;i++) {
        for(int j=1;j<1000005;j++) {
            sv[i][j]=(sv[i][j-1]*a[i])%mod[i];
        }
    }
    for(int i=0;i<2;i++) {
        rev[i][1000004]=fastpow(a[i],mod[i]-1000005,i);
        for(int j=1000003;j>=0;j--) {
            rev[i][j]=(rev[i][j+1]*a[i])%mod[i];
        }
    }
    scanf("%d\n",&n);
    scanf("%s",str);
    len=strlen(str);
    for(int i=0;i<2;i++) {
        phash[i].push_back(0);
    }
    for(int i=0;i<2;i++) {
        for(int j=0;j<len;j++) {
            phash[i].push_back((phash[i][j]+str[j]*sv[i][j])%mod[i]);
        }
    }
    printf("%s",str);
    for(int ind=1;ind<n;ind++) {
        scanf("%s",tem);
        int l=strlen(tem);
        vector<long long> ph[2];
        for(int i=0;i<2;i++) {
            ph[i].push_back(0);
        }
        for(int i=0;i<2;i++) {
            for(int j=0;j<l;j++) {
                ph[i].push_back((ph[i][j]+tem[j]*sv[i][j])%mod[i]);
            }
        }
        int maxi=0;
        for(int i=1;i<=len&&i<=l;i++) {
            long long fh0=phash[0][len]-phash[0][len-i];
            fh0%=mod[0];
            if (fh0<0) {
                fh0+=mod[0];
            }
            fh0*=rev[0][len-i];
            fh0%=mod[0];
            long long fh1=phash[1][len]-phash[1][len-i];
            fh1%=mod[1];
            if (fh1<0) {
                fh1+=mod[1];
            }
            fh1*=rev[1][len-i];
            fh1%=mod[1];
            long long bh0=ph[0][i]-ph[0][0];
            bh0%=mod[0];
            if (bh0<0) {
                bh0+=mod[0];
            }
            long long bh1=ph[1][i]-ph[1][0];
            bh1%=mod[1];
            if (bh1<0) {
                bh1+=mod[1];
            }
            if (fh0==bh0&&fh1==bh1) {
                maxi=i;
            }
        }
        for(int i=0;i<2;i++) {
            for(int j=maxi;j<l;j++) {
                phash[i].push_back((phash[i][len+j-maxi]+tem[j]*sv[i][len+j-maxi])%mod[i]);
            }
        }
        len+=l-maxi;
        for(int i=maxi;i<l;i++) {
            printf("%c",tem[i]);
        }
    }
}