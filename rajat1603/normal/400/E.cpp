#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
const int N = 100005;
const int LN = 17;
int arr[N];
int n,m;
set< pair < int , int> > s[LN];
long long ans = 0;
int main(){
    scanf("%d %d",&n,&m);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d",&arr[i]);
    }
    for(int i = 0 ; i < LN ; ++i){
        int j = 1;
        while(j<=n&&!((arr[j]>>i)&1)){
            ++j;
        }
        int start = j;
        int finish = j;
        for(;j<=n;++j){
            if(!((arr[j]>>i)&1)){
                finish = j-1;
                if(finish>=start){
                    s[i].insert(mp(finish,start));
                    ans+=(1LL<<i)*((1LL*(finish - start + 1) * (finish - start + 2))>>1);
                }
                start = j+1;
            }
        }
        if((arr[n]>>i)&1){
            finish = n;
            s[i].insert(mp(finish,start));
            ans+=(1LL<<i)*((1LL*(finish - start + 1) * (finish - start + 2))>>1);   
        }
    }
    while(m--){
        int pos , val;
        scanf("%d %d",&pos,&val);
        for(int i = 0 ; i < LN ; ++i){
            if(((arr[pos]>>i)&1)==((val>>i)&1)){
                continue;
            }
            else{
                if((arr[pos]>>i)&1){
                    pair < int , int > temp = *s[i].lower_bound(mp(pos,-1));
                    s[i].erase(s[i].find(temp));
                    int start = temp.second;
                    int finish = temp.first;
                    ans-=(1LL<<i)*((1LL*(finish - start + 1) * (finish - start + 2))>>1);
                    finish = pos - 1;
                    if(finish>=start)
                        s[i].insert(mp(finish,start));
                    ans+=(1LL<<i)*((1LL*(finish - start + 1) * (finish - start + 2))>>1);
                    finish = temp.first;
                    start = pos+1;
                    if(finish>=start)
                        s[i].insert(mp(finish,start));
                    ans+=(1LL<<i)*((1LL*(finish - start + 1) * (finish - start + 2))>>1);
                }
                else{
                    if(pos==1){
                        if((arr[2]>>i)&1){
                            pair < int , int > temp = *s[i].lower_bound(mp(pos,-1));
                            s[i].erase(s[i].find(temp));
                            int start = temp.second;
                            int finish = temp.first;
                            ans-=(1LL<<i)*((1LL*(finish - start + 1) * (finish - start + 2))>>1);
                            start = 1;
                            ans+=(1LL<<i)*((1LL*(finish - start + 1) * (finish - start + 2))>>1);
                            s[i].insert(mp(finish,start));
                        }
                        else{
                            ans+=1<<i;
                            s[i].insert(mp(1,1));
                        }
                    }
                    else if(pos==n&&n>1){
                        if((arr[n-1]>>i)&1){
                            pair < int , int > temp = *s[i].lower_bound(mp(n-1,-1));
                            s[i].erase(s[i].find(temp));
                            int start = temp.second;
                            int finish = temp.first;
                            ans-=(1LL<<i)*((1LL*(finish - start + 1) * (finish - start + 2))>>1);
                            finish = n;
                            ans+=(1LL<<i)*((1LL*(finish - start + 1) * (finish - start + 2))>>1);
                            s[i].insert(mp(finish,start));
                        }
                        else{
                            ans+=1<<i;
                            s[i].insert(mp(n,n));
                        }
                    }
                    else if(n>1){
                        if((arr[pos-1]>>i)&1){
                            if((arr[pos+1]>>i)&1){
                                pair < int , int > temp = *s[i].lower_bound(mp(pos-1,-1));
                                pair < int , int > temp2 = *s[i].lower_bound(mp(pos+1,-1));
                                s[i].erase(s[i].find(temp));
                                s[i].erase(s[i].find(temp2));
                                int start = temp.second;
                                int finish = temp.first;
                                ans-=(1LL<<i)*((1LL*(finish - start + 1) * (finish - start + 2))>>1);
                                start = temp2.second;
                                finish = temp2.first;
                                ans-=(1LL<<i)*((1LL*(finish - start + 1) * (finish - start + 2))>>1);
                                start = temp.second;
                                finish = temp2.first;
                                s[i].insert(mp(finish,start));
                                ans+=(1LL<<i)*((1LL*(finish - start + 1) * (finish - start + 2))>>1);
                            }
                            else{
                                pair < int , int > temp = *s[i].lower_bound(mp(pos-1,-1));
                                s[i].erase(s[i].find(temp));
                                int start = temp.second;
                                int finish = temp.first;
                                ans-=(1LL<<i)*((1LL*(finish - start + 1) * (finish - start + 2))>>1);
                                finish = pos;
                                s[i].insert(mp(finish,start));
                                ans+=(1LL<<i)*((1LL*(finish - start + 1) * (finish - start + 2))>>1);
                            }
                        }
                        else{
                            if((arr[pos+1]>>i)&1){
                                pair < int , int > temp = *s[i].lower_bound(mp(pos+1,-1));
                                s[i].erase(s[i].find(temp));
                                int start = temp.second;
                                int finish = temp.first;
                                ans-=(1LL<<i)*((1LL*(finish - start + 1) * (finish - start + 2))>>1);
                                start = pos;
                                s[i].insert(mp(finish,start));
                                ans+=(1LL<<i)*((1LL*(finish - start + 1) * (finish - start + 2))>>1);
                            }
                            else{
                                ans+=1<<i;
                                s[i].insert(mp(pos,pos));
                            }
                        }
                    }
                }
            }
        }
        arr[pos] = val;
        printf("%lld\n",ans);
    }
}