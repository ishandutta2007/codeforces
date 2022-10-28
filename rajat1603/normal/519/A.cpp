#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define getchar_unlocked getchar//for codeforces and timus
inline int scan(){
    char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }
    return x;
}
int main(){
    int white=0;
    int black=0;
    int score[200]={0};
    /*the queen's weight is 9,
the rook's weight is 5,
the bishop's weight is 3,
the knight's weight is 3,
the pawn's weight is 1,*
 'Q', the rook  as 'R', the bishop  as'B', the knight  as 'N', the pawn  as 'P', the king  as 'K'. */
    score['Q']=9;
    score['q']=9;
    score['R']=5;
    score['r']=5;
    score['B']=3;
    score['b']=3;
    score['N']=3;
    score['n']=3;
    score['P']=1;
    score['p']=1;
    for(int i=0;i<8;i++){
        char a[10]={NULL};
        scanf("%s",a);
        for(int j=0;j<8;j++){
            if(a[j]<='Z'){
                white+=score[a[j]];
            }
            else if(a[j]>='a'){
                black+=score[a[j]];
            }
        }
    }
    if(black>white){
        printf("Black");
    }
    else if(white>black){
        printf("White");
        //racist
    }
    else{
        printf("Draw");
        //equality
    }
}