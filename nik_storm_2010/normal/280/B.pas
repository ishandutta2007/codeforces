var
    st:array[1..100000] of longint; leng,ans,n,i,x:longint;


begin

  readln(n); leng:=0; ans:=0;
  for i:=1 to n do
  begin
    read(x);
    while (leng>0) and (x>=st[leng]) do
    begin
      if x xor st[leng]>ans then ans:=x xor st[leng];
      dec(leng);
    end;
    if (leng>0) and (x xor st[leng]>ans) then ans:=x xor st[leng];
    inc(leng); st[leng]:=x;
  end;
  writeln(ans);

end.