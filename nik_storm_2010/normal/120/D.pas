uses
    math;
var
    a: array[1..50,1..50] of longint;
    x1,y1,z1,i,n,m,j,i1,j1,answer,sum1,sum2,sum3,s1,s2,s3,t,x,y,z: longint;



Begin

  assign(input,'input.txt');
   reset(input);
    readln(n,m);
     for i:=1 to n do
      begin
       for j:=1 to m do read(a[i,j]);
        readln;
      end;
     readln(x,y,z);
  close(input);

  answer:=0;
   x1:=min(x,y); x1:=min(z,x1);
    z1:=max(x,y); z1:=max(z,z1);
     y1:=x+y+z-x1-z1;

   //  
    for i:=1 to n-2 do
     for j:=i+1 to n-1 do
      begin
       sum1:=0;
        for i1:=1 to i do
         for j1:=1 to m do sum1:=sum1+a[i1,j1];
       sum2:=0;
        for i1:=i+1 to j do
         for j1:=1 to m do sum2:=sum2+a[i1,j1];
       sum3:=0;
        for i1:=j+1 to n do
         for j1:=1 to m do sum3:=sum3+a[i1,j1];

       s1:=min(sum1,sum2); s1:=min(sum3,s1);
        s3:=max(sum1,sum2); s3:=max(sum3,s3);
         s2:=sum1+sum2+sum3-s1-s3;
          if (s1=x1) and (s2=y1) and (s3=z1) then inc(answer);
      end;

   //  
    for i:=1 to m-2 do
     for j:=i+1 to m-1 do
      begin
       sum1:=0;
        for j1:=1 to i do
         for i1:=1 to n do sum1:=sum1+a[i1,j1];
       sum2:=0;
        for j1:=i+1 to j do
         for i1:=1 to n do sum2:=sum2+a[i1,j1];
       sum3:=0;
        for j1:=j+1 to m do
         for i1:=1 to n do sum3:=sum3+a[i1,j1];

       s1:=min(sum1,sum2); s1:=min(sum3,s1);
        s3:=max(sum1,sum2); s3:=max(sum3,s3);
         s2:=sum1+sum2+sum3-s1-s3;
          if (s1=x1) and (s2=y1) and (s3=z1) then inc(answer);
      end;

  assign(output,'output.txt');
   rewrite(output);
    writeln(answer);
  close(output);

End.