#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
#include <stdio.h>

using namespace std;
typedef long long ll;
ll big = 1000000007ll;
int n,m,k;


int sqpar[3000][11][11];
int sqi = 487;
int nsq;
std::vector<ll> per;

std::vector<ll> upds;
std::vector<ll> upde;
std::vector<ll> S;
std::vector<ll> E;

int geti(ll i){
if(upds[i/sqi] > upde[i]){E[i] = S[i/sqi];return S[i/sqi];}
else{return E[i];}
}

int main()
{
    int c1,c2,c3,c4,c5;
    int a,b,c,d,e,f;
    int x,y,z;
    string s;

    //scanf("%d%d%d" , &n,&m,&k);
    std::cin >> n >> m >> k;
    std::cin >> s;

    int l,r;
    char ch;


    for(c1=0;c1<n;c1++){
        E.push_back(int(s[c1])-97);
        upde.push_back(0);
    }
    nsq = 0;
    for(c1=0;c1<k;c1++){per.push_back(c1);}

    for(c1=0;c1<n;c1+=sqi){
        S.push_back(0);
        upds.push_back(-1);
    nsq++;
    }

    for(c1=0;c1<nsq;c1++){
        for(c2=0;c2<k;c2++){
            for(c3=0;c3<k;c3++){
                sqpar[c1][c2][c3] = 0;
            }
        }
    }

    for(c1=0;c1<nsq;c1++){
        for(c2=c1*sqi;c2<min(c1*sqi+sqi,n-1);c2++){
            sqpar[c1][E[c2]][E[c2+1]]++;
        }
    }
    int ans;
    for(c1=1;c1<=m;c1++){


        std::cin >> x;
        if(x == 1){

            std::cin >> l >> r >> ch;
            l--;
            r--;
            y = int(ch)-97;

            //std::cout << "1\n";
            c2=l;
            a = geti(l);
            b = geti(r);
            while(c2%sqi != 0 && c2 < r){
                        sqpar[c2/sqi][geti(c2)][geti(c2+1)]--;
                        sqpar[c2/sqi][y][y]++;

                        if(c2 != l){
                        E[c2] = y;
                        upde[c2] = c1;}

                c2++;

            }
            //std::cout << "2\n";
            while(c2+sqi < r){

                S[c2/sqi] = y;
                upds[c2/sqi] = c1;

                for(c3=0;c3<k;c3++){
                    for(c4=0;c4<k;c4++){
                        sqpar[c2/sqi][c3][c4]=0;
                    }
                }
                sqpar[c2/sqi][y][y] += sqi;
                c2+=sqi;
            }
            //std::cout << "3\n";
            while(c2 < r){
                            sqpar[c2/sqi][geti(c2)][geti(c2+1)]--;
                            sqpar[c2/sqi][y][y]++;
                            if(c2 != l){
                            E[c2] = y;
                            upde[c2] = c1;}
                c2++;
            }


            //cout << sqpar[0][1][1] << "   A \n";

            if(l > 0){
                sqpar[(l-1)/sqi][geti(l-1)][a]--;
                sqpar[(l-1)/sqi][geti(l-1)][y]++;

                //std::cout << "\nl:  " <<  geti(l-1) << "   " << geti(l) << "\n";
            }
            if(r < n-1){
                sqpar[(r)/sqi][b][geti(r+1)]--;
                sqpar[(r)/sqi][y][geti(r+1)]++;


            }
            E[r] = y;
            upde[r] = c1;

            E[l] = y;
            upde[l] = c1;


        }
        else{

            std::cin >> s;
            for(c2=0;c2<k;c2++){

                per[int(s[c2])-97] = c2;

            }

            ans = 0;

            for(c2=0;c2<nsq;c2++){

                for(c3=0;c3<k;c3++){
                    for(c4=0;c4<k;c4++){

                        //cout << c3 << "--" << c4 << ":    " << sqpar[c2][c3][c4] << "\n";
                        if(per[c3] >= per[c4]){ans += sqpar[c2][c3][c4];}

                    }
                }
            //cout << "\n";
            }

            //std::cout << ans+1 << "\n";
            printf("%d\n",ans+1);

        }

    }


	return 0;
}