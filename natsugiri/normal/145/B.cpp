#include<cstdio>

int main(){
  int i,a1,a2,a3,a4,p=0;
  scanf("%d%d%d%d",&a1,&a2,&a3,&a4);

  a4-=a3-1;
  a1-=a3;
  a2-=a3;
  if(a4==2){a1--;a2--;p=3;}
  if(a4==1){
    if(a1){a1--;p=1;}
    else{a2--;p=2;}
  }
  if(a1<0||a2<0||a4>2||a4<0){
    puts("-1");
  }else{
    if(p&2)printf("7");
    for(i=0;i<a1;i++)printf("4");
    for(i=0;i<a3;i++)printf("47");
    for(i=0;i<a2;i++)printf("7");
    if(p&1)printf("4");
    puts("");
  }

  return 0;
}