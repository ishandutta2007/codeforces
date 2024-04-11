var
  a:array[0..2000000,'a'..'z'] of longint; good:array[97..122] of char;
  s:ansistring; ans,res,cnt,d,k,i,j,cur:longint;


begin

  readln(s);
  for i:=1 to 26 do read(good[96+i]);
  readln(k);
  d:=length(s); ans:=0; cnt:=0;
  for i:=1 to d do
  begin
    res:=0; cur:=0;
    for j:=i to d do
    begin
      if good[ord(s[j])]='0' then inc(res);
      if res>k then break else
      begin
        if a[cur,s[j]]=0 then begin inc(ans); inc(cnt); a[cur,s[j]]:=cnt; end;
        cur:=a[cur,s[j]];
      end;
    end;
  end;
  writeln(ans);

end.