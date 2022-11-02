var
  a:array[1..100] of longint; code,cur,ans,hh,mm,n,i,k:longint; s:string;


begin

  readln(n);
  for i:=1 to n do
  begin
    readln(s);
    val(s[2]+s[3],hh,code); val(s[5]+s[6],mm,code);
    cur:=hh*60+mm;
    a[i]:=(cur mod 720); if s[8]='p' then a[i]:=a[i]+720;
  end;
  ans:=1; k:=1;
  for i:=1 to n-1 do
  begin
    if a[i]=a[i+1] then
    begin
      inc(k);
      if k>10 then begin inc(ans); k:=1; end;
    end
    else
    begin
      k:=1; if a[i]>a[i+1] then inc(ans);
    end;
  end;
  writeln(ans);

end.