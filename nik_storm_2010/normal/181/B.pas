var
    g:array[-1000..1000,-1000..1000] of byte; n,i,j,ans,xx,yy:longint;
     a:array[1..2,1..3000] of longint; x,y:extended;



begin

  readln(n);
  for i:=1 to n do
    begin
      readln(xx,yy);
        a[1,i]:=xx; a[2,i]:=yy;
      g[xx,yy]:=1;
    end;

  ans:=0;
  for i:=1 to n do
    for j:=i+1 to n do
      begin
        x:=(a[1,i]+a[1,j])/2; y:=(a[2,i]+a[2,j])/2;
          if (frac(x)=0) and (frac(y)=0) and (g[trunc(x),trunc(y)]=1)
        then inc(ans);
      end;
  writeln(ans);

end.