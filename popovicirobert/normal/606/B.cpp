#include <cstdio>
char v[100000];
int vf[100001],mat[502][502];
int main(){
   // FILE*fi,*fout;
    int i,j,n,m,con,ns,l,c;
    char a;
    //fi=fopen("B.in" ,"r");
    //fout=fopen("B.out" ,"w");
    scanf("%d%d%d%d" ,&n,&m,&l,&c);
    a=fgetc(stdin);
    a=fgetc(stdin);
    ns=0;
    while(a=='U'||a=='R'||a=='D'||a=='L'){
        v[ns++]=a;
        a=fgetc(stdin);
    }
    con=0;
    mat[l][c]=1;
    while(con<ns){
        if(v[con]=='U'&&l>1)
            l--;
        if(v[con]=='D'&&l<n)
            l++;
        if(v[con]=='L'&&c>1)
            c--;
        if(v[con]=='R'&&c<m)
            c++;
        con++;
        if(mat[l][c]==0)
            mat[l][c]=con+1;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(mat[i][j]==0)
                vf[ns]++;
            else
                vf[mat[i][j]-1]++;
    for(i=0;i<=ns;i++)
       printf("%d " ,vf[i]);
 //   fclose(fi);
   // fclose(fout);
    return 0;
}