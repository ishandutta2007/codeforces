#include <cstring>
#include <cstdio>

const int N = 1e6 + 500;

char A[N], B[N], S[N];
char P[N], rP[N];
bool bio[N], rbio[N];
int n, k;

bool special_A(int i){
    for(;i<n;i++){
        while(i < n && P[S[i]] != '*'){
            if(P[S[i]] > A[i]) return 1;
            if(P[S[i]] < A[i]) return 0;
            i++;
        }
        if(i == n) return 1;
        for(char c = 'a' + k - 1;c >= A[i];c--){
            if(!bio[c]){
                P[S[i]] = c;
                bio[c] = 1;
                break;
            }
        }
        if(P[S[i]] == '*') return 0;
        if(P[S[i]] > A[i])
            return 1;
    }
    if(i == n) return 1;
    return 0;
}

bool special_B(int i){
    for(;i<n;i++){
        while(i < n && P[S[i]] != '*'){
            if(P[S[i]] < B[i]) return 1;
            if(P[S[i]] > B[i]) return 0;
            i++;
        }
        if(i == n) return 1;
        for(char c = 'a';c <= B[i];c++){
            if(!bio[c]){
                P[S[i]] = c;
                bio[c] = 1;
                break;
            }
        }
        if(P[S[i]] == '*') return 0;
        if(P[S[i]] < B[i])
            return 1;
    }
    if(i == n) return 1;
    //printf("ovdje\n");
    return 0;
}

bool solve(){
    int i = 0;
    while(i < n && A[i] == B[i]){
       // printf("i = %d\n", i);
        if(P[S[i]] != '*' && P[S[i]] != A[i]) return 0;
        if(P[S[i]] == '*' && bio[A[i]]) return 0;
        P[S[i]] = A[i];bio[A[i]] = 1;i++;
    }
    if(i == n) return 1;
    if(A[i] > B[i]) return 0;
    if(P[S[i]] != '*'){
        if(P[S[i]] < A[i] || P[S[i]] > B[i]) return 0;
        if(P[S[i]] > A[i] && P[S[i]] < B[i]) return 1;
        if(P[S[i]] == A[i])
            return special_A(i);
        if(P[S[i]] == B[i])
            return special_B(i);
        return 0;
    }
    for(char c = 'a';c<'a'+k;c++){
        rbio[c] = bio[c];
        rP[c] = P[c];
    }
    for(char x = A[i] + 1;x < B[i]; x++){
        if(bio[x]) continue;
        bio[x] = 1;P[S[i]] = x;
        return 1;
    }
    if(!bio[A[i]]){
        P[S[i]] = A[i]; bio[A[i]] = 1;
        if(special_A(i))
            return 1;
    }
    for(char c = 'a';c<'a'+k;c++){
        bio[c] = rbio[c];
        P[c] = rP[c];
    }
    if(!bio[B[i]]){
        P[S[i]] = B[i]; bio[B[i]] = 1;
        if(special_B(i))
            return 1;
    }
    return 0;
}

int main(){
    int T;scanf("%d", &T);
    for(;T--;){
        scanf("%d", &k);
        scanf("%s", S);
        scanf("%s", A);
        scanf("%s", B);
        n = strlen(A);
        for(char c = 'a';c<'a'+k;c++){
            bio[c] = 0;P[c] = '*';
        }
        //printf("kurca\n");
        if(!solve()){
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for(char c = 'a';c<'a'+k;c++)
            bio[c] = 0;
        for(char c = 'a';c<'a'+k;c++)
            bio[P[c]] = 1;
        for(char c = 'a';c<'a'+k;c++){
            if(P[c] == '*'){
                for(char x = 'a';x<'a'+k;x++){
                    if(!bio[x]) {
                        P[c] = x;
                        bio[x] = 1;
                        break;
                    }
                }
            }
            printf("%c", P[c]);
        }
        printf("\n");
        /**
        printf("A : %s\n", A);
        printf("S : ");
        for(int i = 0;i<n;i++) printf("%c", P[S[i]]);
        printf("\n");
        printf("B : %s\n", B);
        printf("##################################\n");
        **/
    }
}