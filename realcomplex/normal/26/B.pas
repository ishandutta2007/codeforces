var
  a:string;
  i,cnt,ans:longint;
begin
  readln(a);
  cnt:=0;
  ans:=0;
  for i:=1 to Length(a) do
  begin
    if a[i]='(' then
      cnt+=1
    else
    begin
      if cnt<>0 then
      begin
        ans+=2;
        cnt-=1;
      end;
    end;
  end;
  writeln(ans);
end.