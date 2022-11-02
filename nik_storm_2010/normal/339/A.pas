var
  a:array[1..100] of longint; s:string; code,d,k,i,j,w:longint;


begin
  readln(s); d:=length(s); k:=0;
  for i:=1 to d do
  begin
    if (i mod 2=0) then continue;
    inc(k);
    val(s[i],a[k],code);
  end;
  for i:=1 to k do
    for j:=i+1 to k do
    if (a[i]>a[j]) then
    begin
      w:=a[i]; a[i]:=a[j]; a[j]:=w;
    end;
  for i:=1 to k do
  begin
    write(a[i]);
    if (i<>k) then write('+');
  end;
end.