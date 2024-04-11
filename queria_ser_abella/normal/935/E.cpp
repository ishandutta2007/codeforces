#include <bits/stdc++.h>
using namespace std;
#define sq(x) ((x)*(x))
#define double long double
#define debug 

char str[100100];
char strr[100100];

int fecha[100100];

int st[100100];

int men[110][10100];
int mai[110][10100];

main(){
    
    scanf(" %s",strr);
    int nn = strlen(strr);
    
    int n = 0;
    for(int i=0;i<nn;i++){
        if(strr[i] >= '0' && strr[i] <= '9'){
            str[n] = '(';
            str[n+1] = strr[i];
            str[n+2] = ')';
            n += 3;
        }
        else {
            str[n] = strr[i];
            n++;
        }
    }
    
    for(int i=0;i<n;i++)
        debug("%c",str[i]);
    debug("\n");
    
    int p,m;
    scanf("%d%d",&p,&m);
    int P = (p<m);
    
    int len = 0;
    for(int i=0;i<n;i++){
        if(str[i] == '(') st[len++] = i;
        if(str[i] == ')') {
            len--;
            fecha[st[len]] = i;
            int A = st[len];
            int B = i;
            if(B == A+2){
                men[0][A] = mai[0][A] = str[A+1] - '0';
                for(int j=1;j<=100;j++){
                    men[j][A] = 99999999;
                    mai[j][A] = -99999999;   
                }
                debug("oi A %d\n",A);
            }
            else {
                int aa = A+1;
                int bb = fecha[aa]+2;
                debug("A %d B %d aa %d bb %d\n",A,B,aa,bb);
                for(int j=0;j<=100;j++){
                    
                    if(P){
                        men[j][A] = 99999999;
                        mai[j][A] = -99999999;
                        for(int k=0;k<j;k++)
                            men[j][A] = min(men[k][aa]+men[j-k-1][bb],men[j][A]),
                            mai[j][A] = max(mai[k][aa]+mai[j-k-1][bb],mai[j][A]);
                        for(int k=0;k<=j;k++){
                            men[j][A] = min(men[k][aa]-mai[j-k][bb],men[j][A]),
                            mai[j][A] = max(mai[k][aa]-men[j-k][bb],mai[j][A]);
                            debug("aa");
                        }
                    }
                    
                    if(!P){
                        
                        men[j][A] = 99999999;
                        mai[j][A] = -99999999;
                        for(int k=0;k<=j;k++){
                            men[j][A] = min(men[k][aa]+men[j-k][bb],men[j][A]),
                            mai[j][A] = max(mai[k][aa]+mai[j-k][bb],mai[j][A]);
                            if(j == 0) debug("%d + %d\n",mai[k][aa],mai[j-k][bb]);
                        }
                        for(int k=0;k<j;k++)
                            men[j][A] = min(men[k][aa]-mai[j-k-1][bb],men[j][A]),
                            mai[j][A] = max(mai[k][aa]-men[j-k-1][bb],mai[j][A]);
                                
                            
                    }
                    
                }
            }
        }
    }
    
    int ans;
    if(P) ans = mai[p][0];
    else ans = mai[m][0];
    
    printf("%d\n",ans);
    
    
    
}