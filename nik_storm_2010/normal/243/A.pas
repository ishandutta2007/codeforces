var
  a:array[0..100000] of longint; f:array[0..1 shl 20] of boolean;
  size,ans,nom,w,n,x,i,j:longint;


begin
  readln(n);
  for nom:=1 to n do
  begin
    read(x);
    for i:=1 to size do a[i]:=a[i] or x;
    inc(size);
    a[size]:=x;
    for i:=1 to size do
      for j:=i+1 to size do
      if (a[i]>a[j]) then
      begin
        w:=a[i]; a[i]:=a[j]; a[j]:=w;
      end;
    x:=0;
    for i:=1 to size do if (a[i]<>a[i-1]) or (i=1) then begin inc(x); a[x]:=a[i]; end;
    size:=x;
    for i:=1 to size do f[a[i]]:=true;
  end;
  for i:=0 to 1 shl 20 do if (f[i]) then inc(ans);
  writeln(ans);
end.