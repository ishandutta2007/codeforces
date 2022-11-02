var
    s,ans:ansistring; i,d,t:longint;


procedure findnext(tek:longint; var ans:longint);
  var i:longint;
begin
  for i:=tek to d do
    if s[i]='.' then
  begin
    ans:=i;
    exit;
  end;
  ans:=-1;
end;


procedure close;
begin
  writeln('NO');
  halt;
end;


begin

  readln(s); d:=length(s); i:=1;
  if (s[1]='.') or (s[d]='.') then close;

  findnext(1,t);
    if (t=-1) or (t-1>8) then close else ans:=copy(s,1,t-1)+'.';
  i:=t+1;
  while i<=d do
    begin
      if s[i]='.' then close; findnext(i,t);
        if t=-1 then
          begin
            if d-i+1<=3 then
              begin
                ans:=ans+copy(s,i,d-i+1);
                i:=d+1;
              end
              else close;
          end
            else
          begin
            if t-i<=11 then
              begin
                if t-i<2 then close;
                  if t-i>3 then
                    begin
                      ans:=ans+s[i]+s[i+1]+s[i+2]+'!';
                      ans:=ans+copy(s,i+3,t-i-3)+'.'; i:=t+1;
                    end
                      else
                    begin
                      ans:=ans+s[i]+'!';
                      ans:=ans+copy(s,i+1,t-i); i:=t+1;
                    end;

              end
                else close;
          end
    end;

  writeln('YES'); d:=length(ans);
  for i:=1 to d do
    if ans[i]='!' then writeln
  else write(ans[i]);

end.