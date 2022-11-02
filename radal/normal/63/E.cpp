#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const long long int N=(1<<19)+20,mod = 1e9+7,inf=2e18,dlt = 12250,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
bool dp[N];
char s[19];
int main(){
    int x=0;
    rep(i,0,19){
        cin >> s[i];
        if (s[i] == 'O'){
            x+=(1<<i);
        }
    }
    int y = (1<<19);
    rep(i,1,y){
        bool f = 0;
        rep(j,0,19){
            if (i&(1<<j) && !dp[i-(1<<j)]){
                dp[i] =1;
                f = 1;
                break;
            }
            if (j < 18 && i&(1 << j) && i&(1<<(j+1)) && j != 2 && j != 6 && j != 11 && j != 15 && !dp[i-(1<<j)-(1<<(j+1))]){
                dp[i] = 1;
                f = 1;
                break;
            }
            if (j < 17 && i&(1<<j) && i&(1 <<(j+1)) && j != 2 && j != 6 && j != 11 && j != 15 && j != 1 && j != 5 && j != 10 && j != 14){
                if (i&(1<<(j+2)) && !dp[i-(1<<j)-(1<<(j+1))-(1<<(j+2))]){
                    dp[i] = 1;
                    f = 1;
                    break;
                }
            }
        }
        if (f) continue;
        if (i&8 && i&16 && i&32){
            if (i&64 && !dp[i-120]){
                dp[i] = 1;
                continue;
            }
        }
        if (i&128 && i&256 && i&512 && i&1024){
            int sm = 128+256+512;
            sm += 1024;
            if (!dp[i-sm]){
                dp[i] = 1;
                continue;
            }
            sm += 2048;
            if (i&2048 && !dp[i-sm]){
                dp[i] = 1;
                continue;
            }
        }
        if (i&256 && i&512 && i&1024){
            int sm = 256+512+1024+2048;
            if (i&2048 && !dp[i-sm]){
                dp[i] = 1;
                continue;
            }
        }
        int x = 4096;
        if (i&x && i&(2*x) && i&(4*x) && i&(8*x) && !dp[i-x*15]){
            dp[i] = 1;
            continue;
        }
        ///////////////////////////////////
        if (i&1 && i&8){
            if (!dp[i-9]){
                dp[i] = 1;
                continue;
            }
            if (i&128 && !dp[i-137]){
                dp[i] = 1;
                continue;
            }
        }
        if (i&8 && i&128 && !dp[i-136]){
            dp[i] = 1;
            continue;
        }
        int sm;
        if (i&2 && i&16){
            sm = 18;
            if (!dp[i-18]){
                dp[i] = 1;
                continue;
            }
            if (i&256){
                sm += 256;
                if (!dp[i-sm]){
                    dp[i] = 1;
                    continue;
                }
                sm += 4096;
                if (i&4096 && !dp[i-sm]){
                    dp[i] = 1;
                    continue;
                }
            }
        }
        if (i&16 && i&256){
            sm = 16+256;
            if (!dp[i-sm]){
                dp[i] = 1;
                continue;
            }
            sm += 4096;
            if (i&4096 && !dp[i-sm]){
                dp[i] = 1;
                continue;
            }
        }
        if (i&256 && i&4096 && !dp[i-256-4096]){
            dp[i] = 1;
            continue;
        }
        if (i&32 && i&4){
            int sm = 36;
            if (!dp[i-36]){
                dp[i] = 1;
                continue;
            }
            if (i&512){
                sm += 512;
                if (!dp[i-sm]){
                    dp[i] = 1;
                    continue;
                }
                if (i&8192){
                    sm += 8192;
                    if (!dp[i-sm]){
                        dp[i] = 1;
                        continue;
                    }
                    sm += 65536;
                    if (i&65536 && !dp[i-sm]){
                        dp[i] = 1;
                        continue;
                    }
                }
            }
        }
        if (i&32 && i&512){
            sm = 32+512;
            if (!dp[i-sm]){
                dp[i] = 1;
                continue;
            }
            sm += 8192;
            if (i&8192){
                if (!dp[i-sm]){
                    dp[i] = 1;
                    continue;
                }
                sm += 65536;
                if (i&65536 && !dp[i-sm]){
                    dp[i] = 1;
                    continue;
                }
            }
        }
        if (i&512 && i&8192){
            sm = 512+8192;
            if (!dp[i-sm]){
                dp[i] = 1;
                continue;
            }
            sm += 65536;
            if (i&65536 && !dp[i-sm]){
                dp[i] = 1;
                continue;
            }
        }
        if (i&65536 && i&8192 && !dp[i-65536-8192]){
            dp[i] = 1;
            continue;
        }
        if (i&64 && i&1024){
            sm = 1088;
            if (!dp[i-sm]){
                dp[i] = 1;
                continue;
            }
            sm += 16384;
            if (i&16384){
                if (!dp[i-sm]){
                    dp[i] = 1;
                    continue;
                }
                sm += 131072;
                if (i&131072 && !dp[i-sm]){
                    dp[i] = 1;
                    continue;
                }
            }
        }
        if (i&1024 && i&16384){
            sm = 1024+16384;
            if (!dp[i-sm]){
                dp[i] = 1;
                continue;
            }
            sm += 131072;
            if (i&131072 && !dp[i-sm]){
                dp[i] = 1;
                continue;
            }
        }
        if (i&16384 && i&131072 && !dp[i-16384-131072]){
            dp[i] = 1;
            continue;
        }
        if (i&2048 && i&32768){
            if (!dp[i-2048-32768]){
                dp[i] = 1;
                continue;
            }
            if (i&262144 && !dp[i-262144-32768-2048]){
                dp[i] = 1;
                continue;
            }
        }
        if (i&32768 && i&262144 && !dp[i-32768-262144]){
            dp[i] = 1;
            continue;
        }
        if (i&4 && i&64){
            if (!dp[i-68]){
                dp[i] = 1;
                continue;
            }
            if (i&2048 && !dp[i-2048-68]){
                dp[i] = 1;
                continue;
            }
        }
        if (i&2048 && i&64 && !dp[i-64-2048]){
            dp[i] = 1;
            continue;
        }
        if (i&2 && i&32){
            int sm = 34+1024;
            if (!dp[i-34]){
                dp[i] = 1;
                continue;
            }
            if (i&1024){
                if (!dp[i-sm]){
                    dp[i] = 1;
                    continue;
                }
                sm += 32768;
                if (i&32768 && !dp[i-sm]){
                    dp[i] = 1;
                    continue;
                }
            }
        }
        if (i&32 && i&1024){
            int sm = 1056;
            if(!dp[i-sm]){
                dp[i] = 1;
                continue;
            }
            sm += 32768;
            if (i&32768 && !dp[i-sm]){
                dp[i] = 1;
                continue;
            }
        }
        if (i&1024 && i&32768 && !dp[i-33792]){
            dp[i] = 1;
            continue;
        }
        if (i&1 && i&16){
            sm = 17;
            if(!dp[i-sm]){
                dp[i] = 1;
                continue;
            }
            if(i&512){
                sm += 512;
                if (!dp[i-sm]){
                    dp[i] = 1;
                    continue;
                }
                if (i&16384){
                    sm += 16384;
                    if (!dp[i-sm]){
                        dp[i] = 1;
                        continue;
                    }
                    sm += 262144;
                    if (i&262144 && !dp[i-sm]){
                        dp[i] = 1;
                        continue;
                    }
                }
            }
        }
        if (i&16 && i&512){
            sm = 528;
            if (!dp[i-sm]){
                dp[i] = 1;
                continue;
            }
            if (i&16384){
                sm += 16384;
                if(!dp[i-sm]){
                    dp[i] = 1;
                    continue;
                }
                sm += 262144;
                if (i&262144 && !dp[i-sm]){
                    dp[i] = 1;
                    continue;
                }
            }
        }
        if (i&512 && i&16384){
            sm = 512+16384;
            if (!dp[i-sm]){
                dp[i] = 1;
                continue;
            }
            sm += 262144;
            if (i&262144 && !dp[i-sm]){
                dp[i] = 1;
                continue;
            }
        }
        if (i&16384 && i&262144 && !dp[i-16384-262144]){
            dp[i] = 1;
            continue;
        }
        if (i&8 && i&256){
            sm = 264;
            if (!dp[i-sm]){
                dp[i] = 1;
                continue;
            }
            if (i&8192){
                sm += 8192;
                if(!dp[i-sm]){
                    dp[i] = 1;
                    continue;
                }
                sm += 131072;
                if (i&131072 && !dp[i-sm]){
                    dp[i] = 1;
                    continue;
                }
            }
        }
        if (i&256 && i&8192){
            sm = 256+8192;
            if (!dp[i-sm]){
                dp[i] = 1;
                continue;
            }
            sm += 131072;
            if (i&131072 && !dp[i-sm]){
                dp[i] = 1;
                continue;
            }
        }
        if (i&131072 && i&8192 && !dp[i-8192-131072]){
            dp[i] = 1;
            continue;
        }
        if (i&128 && i&4096){
            sm = 128+4096;
            if (!dp[i-sm]){
                dp[i] = 1;
                continue;
            }
            sm += 65536;
            if (i&65536 && !dp[i-sm]){
                dp[i] = 1;
                continue;
            }
        }
        if (i&4096 && i&65536 && !dp[i-4096-65536]){
            dp[i] = 1;
            continue;
        }
    }
    if (!dp[x]) cout << "Lillebror";
    else cout << "Karlsson";
}