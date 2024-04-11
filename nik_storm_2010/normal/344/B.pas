var
  a,b:array[1..3] of longint;
  x,i,j,x1,x2,x3:longint;

begin
  for i:=1 to 3 do begin read(a[i]); b[i]:=i; end;
  if (a[1]+a[2]+a[3]) mod 2<>0 then begin writeln('Impossible'); exit; end;
  for i:=1 to 3 do for j:=i+1 to 3 do
    if (a[i]>a[j]) then
    begin
      x:=a[i]; a[i]:=a[j]; a[j]:=x;
      x:=b[i]; b[i]:=b[j]; b[j]:=x;
    end;
  if (a[3]>a[1]+a[2]) then begin writeln('Impossible'); exit; end;
  x1:=-(a[3]-a[1]-a[2]) div 2;
  x2:=a[2]-x1;
  x3:=a[1]-x1;
  if (b[1]=1) and (b[2]=2) then writeln(x1,' ',x2,' ',x3);
  if (b[1]=1) and (b[2]=3) then writeln(x3,' ',x2,' ',x1);
  if (b[1]=2) and (b[2]=1) then writeln(x1,' ',x3,' ',x2);
  if (b[1]=2) and (b[2]=3) then writeln(x3,' ',x1,' ',x2);
  if (b[1]=3) and (b[2]=1) then writeln(x2,' ',x3,' ',x1);
  if (b[1]=3) and (b[2]=2) then writeln(x3,' ',x1,' ',x2);
end.