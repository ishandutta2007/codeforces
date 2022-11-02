uses
  math;
var
  x,y,z:array[0..100000] of longint;
  xx,yy,zz,m,i,val,d,l,r:longint;
  s:ansistring;

begin
  readln(s);
  d:=length(s);
  for i:=1 to d do
  begin
    x[i]:=x[i-1];
    y[i]:=y[i-1];
    z[i]:=z[i-1];
    if (s[i]='x') then inc(x[i]);
    if (s[i]='y') then inc(y[i]);
    if (s[i]='z') then inc(z[i]);
  end;
  readln(m);
  for i:=1 to m do
  begin
    readln(l,r);
    if (r-l+1<3) then
    begin
      writeln('YES');
      continue;
    end;
    xx:=x[r]-x[l-1];
    yy:=y[r]-y[l-1];
    zz:=z[r]-z[l-1];   
    val:=min(xx,min(yy,zz));
    xx:=xx-val;
    yy:=yy-val;
    zz:=zz-val;
    if (xx<=1) and (yy<=1) and (zz<=1) then writeln('YES') else writeln('NO');                  
  end;
end.