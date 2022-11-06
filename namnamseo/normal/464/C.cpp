#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

typedef pair<int,string*>   query;
typedef     long long       ll;

int qn;
query q[100010];

string* base;

char buffer[100010];

ll modder = 1000000007;

ll  dyn [10][2];
ll  dlen[10][2];
/*
ll pow10(int x){
    if(x==0) return 1 ;
    if(x==1) return 10;
    ll tmp = pow10(x/2);
    tmp=((tmp*tmp)%modder);
    if(x&1) tmp=((tmp*10)%modder);
    return tmp;
}*/

int buildDyn() {
    int cur=1;
    int i,j;
    for(i=0;i<10;i++) dyn[i][0]=i, dlen[i][0]=10;
    const char *tmp;
    int b,sn;
    for(i=qn-1;0<=i;i--){
        for(j=0;j<10;j++) dyn[j][cur]=dyn[j][1^cur], dlen[j][cur]=dlen[j][1^cur];
        b=q[i].first;
        sn=q[i].second->length();
        tmp=q[i].second->c_str();
        dyn [b][ cur ]=0;
        dlen[b][ cur ]=1;
        for(j=0;j<sn;j++){
            /// shifting by 10..00
            dyn [b][cur]*=dlen[tmp[j]-'0'][1^cur];
            dyn [b][cur]%=modder;
            /// adding
            dyn [b][cur]+=dyn[tmp[j]-'0'][1^cur];
            dyn [b][cur]%=modder;
            /// length increase
            dlen[b][cur]*=dlen[tmp[j]-'0'][1^cur];
            dlen[b][cur]%=modder;
        }
        cur^=1;
    }
    return 1^cur;
}

void in(){
    int i,j;
    char buf;
    i=0;
    while(true){
        buf=getchar();
        if(buf<'0' || '9'<buf){
            buffer[i]=0;
            break;
        }
        buffer[i]=buf;
        i++;
    }
    if(i==0) buffer[0]='0';
    base = new string(buffer);
    scanf("%d",&qn);
    for(i=0;i<qn;i++){
        scanf("%d->",&q[i].first);
        for(j=0;;j++){
            buffer[j]=getchar();
            if(buffer[j]<'0' || '9'<buffer[j]){
                buffer[j]=0;
                break;
            }
        }
        q[i].second = new string(buffer);
    }
}

int main()
{
    int i;

    in();

    int cur = buildDyn();
    int sn  = base->length();
    const char* tmp = base->c_str();
    ll ans = 0;
    for(i=0;i<sn;i++){
        ans *= dlen[tmp[i]-'0'][cur];
        ans%=modder;
        ans += dyn[tmp[i]-'0'][cur];
        ans%=modder;
    }
    printf("%I64d\n",ans);
    return 0;
}