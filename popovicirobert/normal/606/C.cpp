#include <cstdio>
#define MAXN 100000
int v[MAXN],poz[MAXN];
void swap(int b,int e,int *x){
    int aux=x[b];
    x[b]=x[e];
    x[e]=aux;
}
void myqsort(int begin,int end){
    int b=begin,e=end,pivot=v[(b+e)/2];
    while(b<=e){
        while(v[b]<pivot) b++;
        while(v[e]>pivot) e--;
        if(b<=e){
            swap(b,e,v);
            swap(b,e,poz);
            b++;e--;
        }
    }
    if(begin<e) myqsort(begin,e);
    if(b<end) myqsort(b,end);
}
int main(){
  //  FILE*fi,*fout;
    int i,n,con,max;
    //fi=fopen("C.in" ,"r");
    //fout=fopen("C.out" ,"w");
    scanf("%d" ,&n);
    for(i=0;i<n;i++){
       scanf("%d" ,&v[i]);
       poz[i]=i;
    }
    myqsort(0,n-1);
    max=0;
    con=1;
    for(i=0;i<n-1;i++)
        if(poz[i]<poz[i+1])
            con++;
        else{
            if(max<con)
                 max=con;
            con=1;
        }
    if(con>max)
        max=con;
    printf("%d" ,n-max);
   // fclose(fi);
    //fclose(fout);
    return 0;
}