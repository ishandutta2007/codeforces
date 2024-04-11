var

    num:array[0..9] of longint; code,test,i,c,n,q,a,b,d,cur,dir:longint; ss,s,sim:string;


begin

  readln(n,q); readln(s);
  for test:=1 to q do
    begin
      readln(a,b); fillchar(num,sizeof(num),0);
      ss:=copy(s,a,b-a+1); d:=length(ss);
      cur:=1; dir:=+1;
      while true do
        begin
          if (ss[cur]='>') then
            begin
              dir:=+1; cur:=cur+dir; if not((1<=cur) and (cur<=d)) then break;
              if (ss[cur]='>') or (ss[cur]='<') then
                begin
                  delete(ss,cur-1,1); cur:=cur-1; d:=d-1;
                end;
            end else
            if (ss[cur]='<') then
              begin
                dir:=-1; cur:=cur+dir; if not((1<=cur) and (cur<=d)) then break;
                if (ss[cur]='>') or (ss[cur]='<') then
                  begin
                    delete(ss,cur+1,1); d:=d-1;
                  end;
              end
                else
              begin
                val(ss[cur],c,code); inc(num[c]);
                if c=0 then
                  begin
                    case dir of
                      +1:begin delete(ss,cur,1); d:=d-1; end;
                      -1:begin delete(ss,cur,1); d:=d-1; cur:=cur-1; end;
                      end;
                  end
                    else
                  begin
                    dec(c); str(c,sim); ss[cur]:=sim[1];
                    cur:=cur+dir;
                  end;
                if not((1<=cur) and (cur<=d)) then break;
              end;
        end;
      for i:=0 to 9 do write(num[i],' '); writeln;
    end;

end.