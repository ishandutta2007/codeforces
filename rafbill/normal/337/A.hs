
import Control.Monad
import Control.Applicative
import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Array

readInt :: IO Integer
readInt = read <$> getLine
readIntList :: IO [Integer]
readIntList = fmap read . words <$> getLine
readIntArray :: Integer -> IO (Array Integer Integer)
readIntArray n = listArray (0, n-1) <$> readIntList
readSortedIntArray :: Integer -> IO (Array Integer Integer)
readSortedIntArray n = listArray (0, n-1) . sort <$> readIntList

main :: IO ()
main = do
  [n, m] <- readIntList
  f <- readSortedIntArray m
  putStrLn . show $ minimum $ flip fmap [n-1..m-1] $ \i -> (f!i) - (f!(i-n+1))